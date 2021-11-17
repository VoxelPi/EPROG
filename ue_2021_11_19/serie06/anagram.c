/*
 * Aufgabe 6.6
 * Peter Smek, 14.11.2021
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts the char c to lowercase.
 */ 
char to_lowercase(char c) {
    // Return c if c is not uppercase.
    if (c < 'A' || c > 'Z') {
        return c;
    }
    
    // Return c in lowercase. See https://www.ascii-code.com/.
    return c + ('a' - 'A');
}

/**
 * Checks if first_str is an anagram of second_str.
 */ 
int anagram(char *first_str, char* second_str) {
    int n = strlen(first_str);

    // If the two strings don't have the same length, they cant be anagram.
    if (n != strlen(second_str)) {
        return 0;
    }

    // Create vector containing all chars of string 1.
    int c_n = n;
    char *c_v = malloc(c_n * sizeof(char));
    for (int i = 0; i < n; ++i) {
        c_v[i] = to_lowercase(first_str[i]);
    }

    // Check if string 2 can be build from the chars in c_v.
    for (int i = 0; i < n; ++i) {
        char c = to_lowercase(second_str[i]);

        // Check if the remaining chars contain c.
        int contained = 0;
        for (int i_c = 0; i_c < c_n; ++i_c) {
            if (c_v[i_c] == c) {
                contained = 1;

                // Remove c from c_v.
                for (int i_c_v = i_c; i_c_v < c_n - 1; ++i_c_v) {
                    c_v[i_c_v] = c_v[i_c_v + 1];
                }
                --c_n;
                break;
            }
        }

        // Return 0 if the remaining chars don't contain the ith char of string 2
        if (!contained) {
            return 0;
        }
    }

    return 1;
}

/**
 * Gets a string from stdin.
 */
char* scan_str(char *str, int *len) {
    // Add character to string.
    char c = 0;
    while (scanf("%c", &c) == 1 && c != '\n') {
        str = realloc(str, (*len + 1) * sizeof(char));
        assert(str != NULL);
        str[*len] = c;

        ++*len;
    }

    // Add 0 string-terminator.
    str = realloc(str, (*len + 1) * sizeof(char));
    assert(str != NULL);
    str[*len] = 0;

    return str;
}

int main() {
    int str_1_len = 0, str_2_len = 0;
    char *str_1 = NULL, *str_2 = NULL;

    // Get sring 1 from the user.
    printf("String 1: ");
    str_1 = scan_str(str_1, &str_1_len);

    // Get sring 2 from the user.
    printf("String 2: ");
    str_2 = scan_str(str_2, &str_2_len);

    // Print if string 1 is an anagram of string 2.
    if (anagram(str_1, str_2)) {
        printf("\"%s\" is an anagram of \"%s\".\n", str_1, str_2);
    } else {
        printf("\"%s\" is not an anagram of \"%s\".\n", str_1, str_2);
    }

    // Free allocated memory.
    free(str_1);
    free(str_2);

    return 0;
}