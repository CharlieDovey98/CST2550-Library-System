#ifndef PERSON_H
#define PERSON_H

// The person.h header file.
#include <iostream>
#include <string>

class Person{
protected:
    std::string name;
    std::string address;
    std::string email;

public:
    std::string getName();
    void setName(std::string &name);
    std::string getAddress();
    void setAddress(std::string &address);
    std::string getEmail();
    void setEmail(std::string &email);
};

#endif // PERSON_H