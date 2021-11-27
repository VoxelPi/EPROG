C_FLAGS = -Wall -std=c99
L_FLAGS = -Wall

.PHONY: all
all: bin/dec2bin

bin/dec2bin: bin/obj/dec2bin.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.c
	gcc $(C_FLAGS) -c -o $@ $<
