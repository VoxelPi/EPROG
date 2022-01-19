#ifndef INCLUDE_PERSON__
#define INCLUDE_PERSON__

#include <string>

class Person
{
private:
    std::string name;
    std::string address;
public:
    Person(const std::string& name, const std::string& address);
    ~Person();

    const std::string& getName() const;
    const std::string& getAddress() const;

    void setName(const std::string& name);
    void setAddress(const std::string& address);

    void print();
};

class Student : public Person
{
private:
    int student_number;
    std::string study;
public:
    Student(const std::string& name, const std::string& address, int student_number, const std::string& study);
    ~Student();

    int getStudentNumber() const;
    const std::string& getStudy() const;

    void setStudy(const std::string& study);

    void print();
};

class Employee : public Person
{
private:
    double salery;
    std::string job;
public:
    Employee(const std::string& name, const std::string& address, double salery, const std::string& job);
    ~Employee();

    double getSalery() const;
    const std::string& getJob() const;

    void setSalery(double salery);
    void setJob(const std::string& job);

    void print();
};




#endif
