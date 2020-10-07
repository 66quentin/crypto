SRC= $(wildcard *.c)
TESTS = $(patsubst %.c, %, $(SRC))
all:$(TESTS)
.PHONY: all clean

$(TESTS): % : %.c
	gcc -o $@ $^ -Wall -lm
	
.PHONY: all_tests

all: $(TESTS)
clean:
	$(RM) $(TESTS)
