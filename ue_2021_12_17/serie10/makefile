C_FLAGS = -Wall --std=c++17
L_FLAGS = -Wall

.PHONY: all
all: bin/matrix_test1

bin/matrix_test1: bin/obj/matrix_test1.o bin/obj/matrix.o matrix.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
