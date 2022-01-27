C_FLAGS = -Wall --std=c++17 -g
L_FLAGS = -Wall -g

.PHONY: all
all: bin/program2 bin/polynomial_test

bin/program2: bin/obj/program2.o
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/polynomial_test: bin/obj/polynomial_test.o bin/obj/polynomial.o polynomial.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
