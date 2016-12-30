CC=gcc
CFLAGS=-std=c11
TARGET=quick_find

$(TARGET): quick_find.c
	$(CC) -o $@ $(CFLAGS) $<

test: $(TARGET)
	./$(TARGET) < input.txt > output.test
	diff output.test output.txt

.PHONY: clean
clean:
	rm -rf $(TARGET) output.txt
