C_FLAGS = -Wall --std=c++17 -g
L_FLAGS = -Wall -g

.PHONY: all
all: bin/matrix_test1 bin/account_test1 bin/matrix_test2 bin/matrix_test3 bin/polynomial_test1 bin/symmetric_matrix_test1 bin/diagonal_matrix_test1 bin/person_test1

bin/matrix_test1: bin/obj/matrix_test1.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp bin/obj/symmetric_matrix.o symmetric_matrix.hpp bin/obj/diagonal_matrix.o diagonal_matrix.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/account_test1: bin/obj/account_test1.o bin/obj/account.o account.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/matrix_test2: bin/obj/matrix_test2.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp bin/obj/symmetric_matrix.o symmetric_matrix.hpp bin/obj/diagonal_matrix.o diagonal_matrix.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/matrix_test3: bin/obj/matrix_test3.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp bin/obj/symmetric_matrix.o symmetric_matrix.hpp bin/obj/diagonal_matrix.o diagonal_matrix.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/polynomial_test1: bin/obj/polynomial_test1.o bin/obj/polynomial.o polynomial.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/symmetric_matrix_test1: bin/obj/symmetric_matrix_test1.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp bin/obj/symmetric_matrix.o symmetric_matrix.hpp bin/obj/diagonal_matrix.o diagonal_matrix.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/diagonal_matrix_test1: bin/obj/diagonal_matrix_test1.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp bin/obj/symmetric_matrix.o symmetric_matrix.hpp bin/obj/diagonal_matrix.o diagonal_matrix.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/person_test1: bin/obj/person_test1.o bin/obj/person.o person.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
