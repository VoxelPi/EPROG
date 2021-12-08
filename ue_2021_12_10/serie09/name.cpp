#include "name.hpp"

#include <assert.h>
#include <iostream>

std::string Name::getFirstName() {
    return first_name;
}

std::string Name::getSurname() {
    return surname;
}

void Name::setFirstName(std::string first_name) {
    this->first_name = first_name;
}

void Name::setSurname(std::string surname) {
    this->surname = surname;
}

void Name::setName(std::string name) {
    int i_last_space;
    for (i_last_space = name.length(); i_last_space >= 0; --i_last_space) {
        if (name[i_last_space] == ' ') {
            break;
        }
    }

    assert(i_last_space != -1);

    this->first_name = name.substr(0, i_last_space);
    this->surname = name.substr(i_last_space + 1, name.length() - i_last_space - 1);
}

void Name::printName() {
    bool first_word = true;
    bool prev_space = false;
    for (int i = 0; i < (int)first_name.length(); ++i) {
        if (first_name[i] == ' ') {
            first_word = false;
            prev_space = true;
            std::cout << ' ';
            continue;
        }

        if (first_word) {
            std::cout << first_name[i];
            continue;
        }

        if (prev_space) {
            std::cout << first_name[i] << '.';
            prev_space = false;
            continue;
        }
    }

    std::cout << ' ' << surname << std::endl;
}