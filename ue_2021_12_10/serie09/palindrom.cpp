/**
 * Aufgabe 9.6
 */

#include <iostream>
#include <string>

bool isPalindrome(std::string word) {
    int length = word.length();

    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << "Enter you word: ";
    std::string word;
    std::cin >> word;

    if (isPalindrome(word)) {
        std::cout << "\"" << word << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << word << "\" is not a palindrome." << std::endl;
    }

    return 0;
}