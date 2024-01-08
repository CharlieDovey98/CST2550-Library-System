#ifndef PERSON_H
#define PERSON_H

// The person.h header file.
#include <string>

class Person{
protected:
    std::string name;
    std::string address;
    std::string email;

public:
    std::string getName() const;
    void setName(std::string &name);
    std::string getAddress() const;
    void setAddress(std::string &address);
    std::string getEmail() const;
    void setEmail(std::string &email);
};

#endif // PERSON_H