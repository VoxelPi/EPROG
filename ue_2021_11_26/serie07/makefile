C_FLAGS = -Wall -std=c99
L_FLAGS = -Wall

.PHONY: all
all: bin/diff bin/matrix1 bin/newton bin/matrix2

bin/diff: bin/obj/diff.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/matrix1: bin/obj/matrix1.o bin/obj/matrix.o matrix.h
	gcc $(L_FLAGS) -o $@ $^

bin/newton: bin/obj/newton.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/matrix2: bin/obj/matrix2.o bin/obj/matrix.o matrix.h
	gcc $(L_FLAGS) -o $@ $^

bin/obj/%.o: %.c
	gcc $(C_FLAGS) -c -o $@ $<
