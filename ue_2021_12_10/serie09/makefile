C_FLAGS = -Wall --std=c++17
L_FLAGS = -Wall

.PHONY: all
all: bin/ellipse_test

bin/ellipse_test: bin/obj/ellipse_test.o bin/obj/ellipse.o ellipse.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
