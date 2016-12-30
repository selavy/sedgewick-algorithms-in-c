CC=gcc
CFLAGS=-std=c11
QUICK_FIND=quick_find
QUICK_UNION=quick_union
WEIGHTED_QUICK_UNION=weighted_quick_union
PATH_COMPRESSION=path_compression
TARGETS=$(QUICK_FIND) $(QUICK_UNION) $(WEIGHTED_QUICK_UNION) $(PATH_COMPRESSION)

all: $(TARGETS)

$(QUICK_FIND): quick_find.c
	$(CC) -o $@ $(CFLAGS) $<
$(QUICK_UNION): quick_union.c
	$(CC) -o $@ $(CFLAGS) $<
$(WEIGHTED_QUICK_UNION): weighted_quick_union.c
	$(CC) -o $@ $(CFLAGS) $<
$(PATH_COMPRESSION): path_compression.c
	$(CC) -o $@ $(CFLAGS) $<

test: $(TARGETS)
	./$(QUICK_FIND) < input.txt > output.quickfind
	diff output.quickfind output.txt
	./$(QUICK_UNION) < input.txt > output.quickunion
	diff output.quickunion output.txt
	./$(WEIGHTED_QUICK_UNION) < input.txt > output.weightedquickunion
	diff output.weightedquickunion output.txt
	./$(PATH_COMPRESSION) < input.txt > output.pathcompression
	diff output.pathcompression output.txt

.PHONY: clean
clean:
	rm -rf $(TARGETS) output.quickfind output.quickunion output.weightedquickunion output.pathcompression
