/*
 * Aufgabe 7.6
 * Peter Smek, 21.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "eratosthenes.h"

Eratosthenes* doEratosthenesSieve(int n_max) {
    // Allocate memory for struct.
    Eratosthenes *eratosthenes = malloc(sizeof(Eratosthenes));

    // Set properties of struct.
    eratosthenes->n_max = n_max;
    eratosthenes->n = n_max - 1;
    eratosthenes->primes = malloc(eratosthenes->n * sizeof(int));
    assert(eratosthenes->primes != NULL);

    // Fill vector with 2..n_max.
    for (int i = 0; i < eratosthenes->n; ++i) {
        eratosthenes->primes[i] = i + 2;
    }

    for (int i_prime = 0; i_prime < eratosthenes->n; ++i_prime) {
        int p = eratosthenes->primes[i_prime]; // primes[i] is a prime because otherwise, it would already have been removed.
        int i_write = 1; // write index.

        for (int i_read = 1; i_read < eratosthenes->n - i_prime; ++i_read) {
            // If primes[i + j] is not divisable by p_i move it to the current write index + 1.
            if (eratosthenes->primes[i_prime + i_read] % p != 0) {
                eratosthenes->primes[i_prime + i_write] = eratosthenes->primes[i_prime + i_read];
                ++i_write;
            }
        }

        // Set new length.
        eratosthenes->n = i_write + i_prime;
    }

    // Reallocate memory for prime-vector.
    eratosthenes->primes = realloc(eratosthenes->primes, eratosthenes->n * sizeof(int));

    // Return pointer to struct.
    return eratosthenes;
}

int main() {

    int n_max = 0;

    // Get n_max from user.
    do {
        printf("n_max = ");
        scanf("%d", &n_max);
    } while (n_max < 1);

    // Filter primes <= n_max.
    Eratosthenes *eratosthenes = doEratosthenesSieve(n_max);

    // Print primes.
    printf("Primes <= %d: (%d)\n", eratosthenes->n_max, eratosthenes->n);
    for (int i = 0; i < eratosthenes->n; ++i) {
        printf("  %d\n", eratosthenes->primes[i]);
    }
    printf("Primes <= %d: (%d)\n", eratosthenes->n_max, eratosthenes->n);

    // Free allocated memory.
    free(eratosthenes->primes);
    free(eratosthenes);

    return 0;
}