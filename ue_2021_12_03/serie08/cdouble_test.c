/**
 * Aufgabe 8.7
 */

#include <assert.h>
#include <stdio.h>

#include "cdouble.h"

int main() {
    // Create new complex number z.
    cDouble *z = newCDouble(1.5, 2.3);
    assert(getCDoubleReal(z) == 1.5);
    assert(getCDoubleImag(z) == 2.3);

    // Set real part of z.
    setCDoubleReal(z, 4.2);
    assert(getCDoubleReal(z) == 4.2);

    // Set imaginary part of z.
    setCDoubleImag(z, 3.6);
    assert(getCDoubleImag(z) == 3.6);

    // Delete z.
    z = delCDouble(z);

    // Get complex nummber z from user.
    z = scanCDouble();

    // Print complex number z. 
    printf("z = ");
    printCDouble(z);

    // Delete z.
    z = delCDouble(z);

    printf("All tests passed!\n");

    return 0;
}