/**
 * Aufgabe 9.4
 */

#include <cassert>
#include <iostream>
#include <string>

class University {
private:
    std::string name;
    std::string city;
    int num_students;

public:
    std::string getName();
    std::string getCity();
    int getNumStudents();

    void setName(std::string name);
    void setCity(std::string city);
    void setNumStudents(int numStudents);

    void graduate();
    void newStudent();
};

std::string University::getName() {
    return name;
}

std::string University::getCity() {
    return city;
}

int University::getNumStudents() {
    return num_students;
}

void University::setName(std::string name) {
    this->name = name;
}

void University::setCity(std::string city) {
    this->city = city;
}

void University::setNumStudents(int num_students) {
    assert(num_students >= 0);
    this->num_students = num_students;
}

void University::graduate() {
    assert(num_students >= 1);
    --num_students;
}

void University::newStudent() {
    ++num_students;
}

int main() {
    University uni;
    uni.setName("TU");
    uni.setCity("Wien");
    uni.setNumStudents(26529);

    assert(uni.getName() == "TU");
    assert(uni.getCity() == "Wien");
    assert(uni.getNumStudents() == 26529);

    std::cout << "Name: " << uni.getName() << std::endl;
    std::cout << "City: " << uni.getCity() << std::endl;
    std::cout << "Student count: " << uni.getNumStudents() << std::endl;

    uni.newStudent();
    uni.newStudent();
    std::cout << "Student count: " << uni.getNumStudents() << std::endl;
    uni.graduate();
    std::cout << "Student count: " << uni.getNumStudents() << std::endl;

    return 0;
} 