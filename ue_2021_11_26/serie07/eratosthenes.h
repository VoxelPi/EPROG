#ifndef INCLUDE_MATRIX__
#define INCLUDE_MATRIX__

/*
 * Aufgabe 7.6
 * Peter Smek, 21.11.2021
 */

typedef struct _Eratosthenes_ {
    int n_max;
    int n;
    int *primes;
} Eratosthenes;

Eratosthenes* doEratosthenesSieve(int n_max);

#endif