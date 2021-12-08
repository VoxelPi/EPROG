/**
 * Aufgabe 9.7
 */

#include "name.hpp"

#include <assert.h>
#include <iostream>

int main() {
    Name name;
    name.setFirstName("Foo");
    name.setSurname("Bar");
    
    assert(name.getFirstName() == "Foo");
    assert(name.getSurname() == "Bar");

    std::cout << "First name is: \"" << name.getFirstName() << "\"" << std::endl;
    std::cout << "Surname is: \"" << name.getSurname() << "\"" << std::endl;
    std::cout << "Name is: ";
    name.printName();
    
    std::cout << std::endl;
    name.setName("Max Maxi Maximilian Mustermann");
    
    assert(name.getFirstName() == "Max Maxi Maximilian");
    assert(name.getSurname() == "Mustermann");

    std::cout << "First name is: \"" << name.getFirstName() << "\"" << std::endl;
    std::cout << "Surname is: \"" << name.getSurname() << "\"" << std::endl;
    std::cout << "Name is: "; 
    name.printName();

    return 0;
}