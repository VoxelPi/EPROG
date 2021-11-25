C_FLAGS = -Wall -std=c99
L_FLAGS = -Wall

.PHONY: all
all: bin/diff bin/matrix1 bin/newton bin/matrix2 bin/matrixVector bin/eratosthenes bin/merge bin/mergesort

bin/diff: bin/obj/diff.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/matrix1: bin/obj/matrix1.o bin/obj/matrix.o matrix.h
	gcc $(L_FLAGS) -o $@ $^

bin/newton: bin/obj/newton.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/matrix2: bin/obj/matrix2.o bin/obj/matrix.o matrix.h
	gcc $(L_FLAGS) -o $@ $^

bin/matrixVector: bin/obj/matrixVector.o bin/obj/matrix.o bin/obj/vector.o matrix.h vector.h
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/eratosthenes: bin/obj/eratosthenes.o eratosthenes.h
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/merge: bin/obj/merge.o
	gcc $(L_FLAGS) -o $@ $^

bin/mergesort: bin/obj/mergesort.o
	gcc $(L_FLAGS) -o $@ $^

bin/obj/%.o: %.c
	gcc $(C_FLAGS) -c -o $@ $<
