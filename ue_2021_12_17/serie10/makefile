C_FLAGS = -Wall --std=c++17
L_FLAGS = -Wall

.PHONY: all
all: bin/matrix_test1 bin/polynomial_test1 bin/matrix_test2

bin/matrix_test1: bin/obj/matrix_test1.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/polynomial_test1: bin/obj/polynomial_test1.o bin/obj/polynomial.o polynomial.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/matrix_test2: bin/obj/matrix_test2.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
