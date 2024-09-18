#ifndef BOOKING_H_INCLUDED
#define BOOKING_H_INCLUDED

#include <map>
#include <unordered_map>
#include <vector>

#include "Customer.h"
#include "Bus.h"
#include "Ticket.h"

class Booking
{
public:
    static std::map<int, Customer> customerMap;
    static std::vector<Bus> busVector;
    static std::map<int, Ticket> ticketList;

    void addTocustomerMap(int id, std::string name, int age, char gender, std::string password); // add customer to customer map
    bool exist(int id); // check in customer map if id exist or not

    void signup(); // new sign up ----> ask for customers more details..
    void AuthenticateAndLogin(); // authenticate the id and password to enter the login(green Bus) page
    void greenBusBookingPage(int cusId); // Green bus module page.........
    void greenModules(); // show the module details..1) Booking 2) cancel.....

    void bookTicket(int bId, int cusId);
    void viewTicketofBus(); // view ticket filled / Seats of the Bus..
    void summary();
    void cancelTicket(int cusId);
    void restoreSeats(std::string busType, std::string seatType, std::vector<std::string> seating);
};

#endif // BOOKING_H_INCLUDED
