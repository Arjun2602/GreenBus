#include "Customer.h"

Customer::Customer()
:customerId(0),name(""),password(""),age(0),gender(' ')
{

}

Customer::Customer(int customerId, std::string name, std::string password, int age, char gender)
{
    this->customerId = customerId;
    this->name = name;
    this->password = password;
    this->age = age;
    this->gender = gender;
}

