// Library Management System, The person.h header file.
#ifndef PERSON_H
#define PERSON_H

#include <string>

// Declaring the person class' variables, methods and identifiers.
class Person{
protected:
    std::string name;
    std::string address;
    std::string email;

public:
    std::string getName() const;
    void setName(std::string name);
    std::string getAddress() const;
    void setAddress(std::string address);
    std::string getEmail() const;
    void setEmail(std::string email);
};

#endif // PERSON_H