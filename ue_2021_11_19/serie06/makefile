C_FLAGS = -Wall -std=c99
L_FLAGS = -Wall

.PHONY: all
all: bin/selectionsort bin/unique bin/meanVariance bin/sampleVector bin/appendVector bin/anagram bin/squareVec bin/cut

bin/selectionsort: $(patsubst %,bin/obj/%.o,selectionsort)
	gcc $(L_FLAGS) -o $@ $^

bin/unique: $(patsubst %,bin/obj/%.o,unique)
	gcc $(L_FLAGS) -o $@ $^

bin/meanVariance: $(patsubst %,bin/obj/%.o,meanVariance)
	gcc $(L_FLAGS) -o $@ $^

bin/sampleVector: $(patsubst %,bin/obj/%.o,sampleVector)
	gcc $(L_FLAGS) -o $@ $^

bin/appendVector: $(patsubst %,bin/obj/%.o,appendVector)
	gcc $(L_FLAGS) -o $@ $^

bin/anagram: $(patsubst %,bin/obj/%.o,anagram)
	gcc $(L_FLAGS) -o $@ $^

bin/squareVec: $(patsubst %,bin/obj/%.o,squareVec)
	gcc $(L_FLAGS) -o $@ $^

bin/cut: $(patsubst %,bin/obj/%.o,cut)
	gcc $(L_FLAGS) -o $@ $^

bin/obj/%.o: %.c
	gcc $(C_FLAGS) -c -o $@ $<
