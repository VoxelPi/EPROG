C_FLAGS = -Wall --std=c++17
L_FLAGS = -Wall

.PHONY: all
all: bin/ellipse_test bin/sparkonto bin/triangle_test bin/university bin/kunde_test bin/palindrom bin/name_test bin/stoppuhr_test

bin/ellipse_test: bin/obj/ellipse_test.o bin/obj/ellipse.o ellipse.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/sparkonto: bin/obj/sparkonto.o
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/triangle_test: bin/obj/triangle_test.o bin/obj/triangle.o triangle.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/university: bin/obj/university.o
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/kunde_test: bin/obj/kunde_test.o bin/obj/kunde.o kunde.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/palindrom: bin/obj/palindrom.o
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/name_test: bin/obj/name_test.o bin/obj/name.o name.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/stoppuhr_test: bin/obj/stoppuhr_test.o bin/obj/stoppuhr.o stoppuhr.hpp
	g++ $(L_FLAGS) -o $@ $^ -lm

bin/obj/%.o: %.cpp
	g++ $(C_FLAGS) -c -o $@ $<
