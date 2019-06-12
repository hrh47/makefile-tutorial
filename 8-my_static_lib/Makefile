CFLAGS = -Wall -Werror -Wextra

SOURCE = hello.o
TARGET = libhello.a

all: $(TARGET) build

build: LDLIBS += $(TARGET)
build: main.o
	$(CC) -o hello main.o $(CFLAGS) $(LDLIBS)

$(TARGET): $(SOURCE)
	ar rcs $(TARGET) $(SOURCE)
	ranlib $(TARGET)

clean:
	-rm *.o hello $(TARGET)
