C_FLAGS = -Wall --std=c++17 -g
L_FLAGS = -Wall -g

.PHONY: all
all: bin/matrix_test1 bin/complex_vector_test1

bin/matrix_test1: bin/obj/matrix_test1.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/complex_vector_test1: bin/obj/complex_vector_test1.o bin/obj/complex_vector.o complex_vector.hpp bin/obj/complex.o complex.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
