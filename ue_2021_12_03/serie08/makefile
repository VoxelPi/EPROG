C_FLAGS = -Wall -std=c99
L_FLAGS = -Wall

.PHONY: all
all: bin/dec2bin bin/polynomial_test bin/dec2float bin/float2dec bin/prodPoly bin/differentiatePolynomial bin/cdouble_test bin/bubblesort

bin/dec2bin: bin/obj/dec2bin.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/polynomial_test: bin/obj/polynomial_test.o bin/obj/polynomial.o polynomial.h
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/dec2float: bin/obj/dec2float.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/float2dec: bin/obj/float2dec.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/prodPoly: bin/obj/prodPoly.o bin/obj/polynomial.o polynomial.h
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/differentiatePolynomial: bin/obj/differentiatePolynomial.o bin/obj/polynomial.o polynomial.h
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/cdouble_test: bin/obj/cdouble_test.o bin/obj/cdouble.o cdouble.h
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/bubblesort: bin/obj/bubblesort.o
	gcc $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.c
	gcc $(C_FLAGS) -c -o $@ $<
