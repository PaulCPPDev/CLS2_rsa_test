EXEC        = main

CC          = gcc
CFLAGS      = -std=c17 -Wall -Wextra -Wpedantic -O3
CFLAGS_DBG  = -std=c17 -Wall -Wextra -Wpedantic -O0 -g
LDFLAGS     =

SRC         = src
INCLUDE     = include

.PHONY: compile
compile: $(EXEC)

$(EXEC): $(SRC)/*.c
	$(CC) $(CFLAGS) -I$(INCLUDE) $^ -o $@ $(LDFLAGS)

.PHONY: compile-debug
compile-debug: CFLAGS = $(CFLAGS_DBG)
compile-debug: compile

.PHONY: run
run: compile
	./$(EXEC)

.PHONY: run-debug
run-debug: compile-debug
	./$(EXEC)

.PHONY: clean
clean:
	rm -f $(EXEC)
