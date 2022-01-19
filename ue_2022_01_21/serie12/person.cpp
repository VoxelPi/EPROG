#include "person.hpp"

#include <iostream>

/*
 * Person
 */ 

Person::Person(const std::string& name, const std::string& address) {
    this->name = name;
    this->address = address;
}

Person::~Person() {}

const std::string& Person::getName() const {
    return name;
}

const std::string& Person::getAddress() const {
    return address;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAddress(const std::string& address) {
    this->address = address;
}

void Person::print() {
    std::cout << "PERSON:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
}

/*
 * Student
 */ 

Student::Student(const std::string& name, const std::string& address, int student_number, const std::string& study) : Person(name, address) {
    this->student_number = student_number;
    this->study = study;
}

Student::~Student() {}

int Student::getStudentNumber() const {
    return student_number;
}

const std::string& Student::getStudy() const {
    return study;
}

void Student::setStudy(const std::string& study) {
    this->study = study;
}

void Student::print() {
    std::cout << "STUDENT:" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Address: " << getAddress() << std::endl;
    std::cout << "Student Number: " << student_number << std::endl;
    std::cout << "Study: " << study << std::endl;
}

/*
 * Employee
 */ 

Employee::Employee(const std::string& name, const std::string& address, double salery, const std::string& job) : Person(name, address) {
    this->salery = salery;
    this->job = job;
}

Employee::~Employee() {}

double Employee::getSalery() const {
    return salery;
}

const std::string& Employee::getJob() const {
    return job;
}

void Employee::setSalery(double salery) {
    this->salery = salery;
}

void Employee::setJob(const std::string& job) {
    this->job = job;
}

void Employee::print() {
    std::cout << "EMPLOYEE:" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Address: " << getAddress() << std::endl;
    std::cout << "Salery: " << salery << std::endl;
    std::cout << "Job: " << job << std::endl;
}