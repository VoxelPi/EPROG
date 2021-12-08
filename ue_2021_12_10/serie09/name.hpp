#ifndef INCLUDE_NAME__
#define INCLUDE_NAME__

#include <string>

class Name
{
private:
    std::string first_name;
    std::string surname;

public:
    std::string getFirstName();
    std::string getSurname();

    void setFirstName(std::string first_name);
    void setSurname(std::string surname);

    void setName(std::string name);
    void printName();
};

#endif
