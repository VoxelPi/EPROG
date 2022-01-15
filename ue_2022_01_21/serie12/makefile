C_FLAGS = -Wall --std=c++17 -g
L_FLAGS = -Wall -g

.PHONY: all
all: bin/matrix_test1 bin/account_test1

bin/matrix_test1: bin/obj/matrix_test1.o bin/obj/matrix.o matrix.hpp bin/obj/vector.o vector.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/account_test1: bin/obj/account_test1.o bin/obj/account.o account.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
