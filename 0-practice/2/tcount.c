#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_algos.h"

typedef struct Data {
	char *key;
	int count;
} Data;

Data *Data_create(char *key)
{
	Data *data = (Data *)malloc(sizeof(Data));
	data->key = strdup(key);
	data->count = 1;
	return data;
}

int Data_count(ListNode *node)
{
	return ((Data *)(node->value))->count;
}

void Data_remove(ListNode *node)
{
	free(((Data *)(node->value))->key);
}

void Data_destroy(List *list)
{
	LIST_FOREACH(list, first, next, node) {
		Data_remove(node);
	}
}

void increase_count(ListNode *node)
{
	((Data *)(node->value))->count += 1;
}

void decrease_count(ListNode *node)
{
	((Data *)(node->value))->count -= 1;
}

ListNode *find(List *list, char *key)
{
	if (key[0] == '-') {
		key++;
	}
	LIST_FOREACH(list, first, next, node) {
		if (strcmp(((Data *)(node->value))->key, key) == 0) {
			return node;
		}
	}
	return NULL;
}

void print(List *list)
{
	LIST_FOREACH(list, first, next, node) {
		printf("%s:\t%d\n", ((Data *)(node->value))->key, ((Data *)(node->value))->count);
	}
}

int cmp(const void *a, const void *b)
{
	Data *x = (Data *)a;
	Data *y = (Data *)b;

	if (x->count != y->count) {
		return y->count - x->count; 
	} else {
		return strcmp(x->key, y->key);
	}
}

void tcount(List *list)
{
	char line[1000];
	ListNode *to_find = NULL;
	while (fgets(line, 1000, stdin) != NULL) {
		line[strlen(line) - 1] = '\0';
		to_find = find(list, line);
		if (line[0] != '-') {
			if (to_find) {
				increase_count(to_find);
			} else {
				List_push(list, Data_create(line));
			}
		} else {
			if (to_find) {
				decrease_count(to_find);
				if (Data_count(to_find) <= 0) {
					Data_remove(to_find);
					List_remove(list, to_find);
				}
			}
		}
	}
	List_bubble_sort(list, cmp);
	print(list);
	Data_destroy(list);
}

int main()
{
	List *list = List_create();
	tcount(list);
	List_clear_destroy(list);
	return 0;
}
