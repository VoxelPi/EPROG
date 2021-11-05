/*
 * Aufgabe 4.4
 * Peter Smek, 29.10.2021
 */

#include <stdio.h>

/**
 * Gets the user input for a variable T. The input request is repeated,
 * until a value for T greater than 0 is entered
 */ 
double scanfpositive() {
    double T = 0;

    // Repeat input request until user input > 0.
    do {
        printf("T = ");
        scanf("%lf", &T);
    } while (T <= 0);

    // Return user input.
    return T;
}

int main() {
    // Gets the user input.
    double T = scanfpositive();

    // Prints the user input.
    printf("User input is %f\n", T);

    return 0;
}

/*
 * Tests:
 * Test negative values.
 * Test T = 0.
 * Test positive values.
 */ 