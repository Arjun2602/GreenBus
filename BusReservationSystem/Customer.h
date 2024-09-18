#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <string>

class Customer
{
public:
    static int id;
    int customerId;
    std::string name;
    std::string password;
    int age;
    char gender;

    Customer();
    Customer(int customerId, std::string name, std::string password, int age, char gender);


};

#endif // CUSTOMER_H_INCLUDED
