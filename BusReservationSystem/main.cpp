#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "Customer.h"
#include "Bus.h"
#include "Booking.h"

using namespace std;

void createObjects()
{
    Booking::customerMap[1] = Customer(1,"aaa","111",24,'F');
    Booking::customerMap[2] = Customer(2,"bbb","222",61,'M');
    Booking::customerMap[3] = Customer(3,"ccc","333",22,'M');
    Booking::customerMap[4] = Customer(4,"ddd","444",36,'F');

    Booking::busVector.push_back(Bus("ac","seater"));
    Booking::busVector.push_back(Bus("ac","sleeper"));
    Booking::busVector.push_back(Bus("non-ac","seater"));
    Booking::busVector.push_back(Bus("non-ac","sleeper"));
}

void homePage()
{
    cout << "\nWelcome to Home Page..";
    cout << "\n1.Customer sign-up";
    cout << "\n2.Customer login";
    cout << "\n3.Exit";
    cout << "\n4.Printobjs" << endl;
}
int main()
{
    createObjects();
    cout << "\t\tWelcome Bus Reservation System";

    bool flag = true;
    int choice = 0;
    while(flag)
    {
        homePage();
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                // sign up
                Booking b;
                b.signup();
                break;
            }
        case 2:
            {
                // log in
                Booking b;
                b.AuthenticateAndLogin();
                break;
            }
        case 3:
            {
                flag = false;
                break;
            }
        case 4:
            {
               for(auto it = Booking::customerMap.begin(); it != Booking::customerMap.end(); it++)
               {
                   Customer c = it->second;
                   cout << c.customerId << " " << c.name << " " << c.age << " " << c.gender << " " << c.password << endl;
               }
               for(Bus b : Booking::busVector)
               {
                    cout << b.busType << " " << b.seatType << endl;
               }
               break;
            }
        default:
            {
                cout << "\nInvalid Try!!";
                break;
            }
        }
    }

}
