CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = military

$(TARGET): main.c vehicle.h
 $(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
 rm -f $(TARGET)

run: $(TARGET)
 ./$(TARGET)

.PHONY: clean run
