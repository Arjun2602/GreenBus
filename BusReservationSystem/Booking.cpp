#include <iostream>

#include "Booking.h"

std::map<int, Customer> Booking::customerMap; // customer map details......
std::vector<Bus> Booking::busVector; // Bus details in vectors......
std::map<int, Ticket> Booking::ticketList; // ticket List....
// sign up method........
void Booking::signup()
{
    static int customerId = 5;
    int id = customerId++;
    std::string name;
    std::string password;
    int age;
    char gender;

    std::cout << "\nEnter name: ";
    std::cin >> name;
    std::cout << "\nEnter age: ";
    std::cin >> age;
    std::cout << "\nEnter gender: ";
    std::cin >> gender;
    std::cout << "\nEnter password: ";
    std::cin >> password;

    addTocustomerMap(id, name, age, gender, password);
    std::cout << "\nRegistered Successfully!!"<< std::endl;
    return;
}

// add customer details to customer map...........
void Booking::addTocustomerMap(int id, std::string name, int age, char gender, std::string password)
{
    Booking::customerMap[id] = Customer(id,name,password,age,gender);
}
// check if id is in customer map...
bool Booking::exist(int id)
{
    if(Booking::customerMap.find(id) != Booking::customerMap.end())
    {
        return true;
    }return false;
}
// Authenticate and login method....
void Booking::AuthenticateAndLogin()
{
    int id;
    std::string password;

    std::cout << "\nEnter Id: ";
    std::cin >> id;

    if(!exist(id))
    {
        std::cout << "\nInvalid Id!!";
        return;
    }
    std::cout << "\nEnter password: ";
    std::cin >> password;
    Customer c = Booking::customerMap[id];
    if(password != c.password)
    {
        std::cout << "\nInvalid password!!";
        return;
    }
    std::cout << "\nWelcome to Green Bus";
    greenBusBookingPage(id);
}
void Booking::greenModules()
{
    std::cout << "\n1.Book Ticket";
    std::cout << "\n2.View Ticket";
    std::cout << "\n3.Cancel Ticket";
    std::cout << "\n4.Summary";
    std::cout << "\n5.Exit" << std::endl;
}

bool possible(std::vector<std::vector<std::string>>& seats, std::string gender, std::string seatNo)
{
    int n = seats.size();
    int m = seats[0].size();
    for(int i = 0; i < n; i+=2)
    {
        for(int j = 0; j < m; j++)
        {
            if(seats[i][j] == seatNo && seats[i+1][j] == "F")
            {
                return false;
            }else if(seats[i+1][j] == seatNo && seats[i][j] == "F")
            {
                return false;
            }
        }
    }
    return true;
}

// restore seats

void Booking::restoreSeats(std::string busType, std::string seatType, std::vector<std::string> seating)
{
    for(Bus& bus : Booking::busVector)
    {
        if(bus.seatType == seatType && bus.busType == busType)
        {
            for(std::string num : seating){
                int track = 1;
                std::stringstream ss(num);
                int n = 0;
                ss >> n;
                int l = bus.seats.size();
                int k = bus.seats[0].size();
                for(int i = 0; i < l; i++){
                    for(int j = 0; j < k; j++){
                        if(track == n){
                            bus.seats[i][j] = num;
                            track++;
                        }else{
                            track++;
                        }
                    }
                }
            }
        }
    }
    std::cout << "\nCanceled Successfully!!";
}

/*
        cancel Ticket
*/

void Booking::cancelTicket(int cusId)
{
    int bId;
    std::cout << "\nEnter the booking Id: ";
    std::cin >> bId;
    std::string busType;
    std::string seatType;
    std::vector<std::string> seating;
    if(Booking::ticketList.find(bId) == Booking::ticketList.end())
    {
        std::cout << "\nInvalid Booking Id!!";
        return;
    }
    Ticket t = Booking::ticketList[bId];

    if(t.cusId != cusId)
    {
        std::cout << "\nNot the valid ticket!!";
        return;
    }
    busType = t.busType;
    seatType = t.seatType;
    seating = t.seating;
    Booking::ticketList.erase(bId);
    restoreSeats(busType, seatType, seating);
}

/*
            book ticket....
*/
// std::vector<Bus> Booking::busVector; ---> static
void Booking::bookTicket(int bId, int cusId)
{
    int seatCount = 0;
    std::string gender;
    std::string seatNo;
    std::string busType;
    std::string seatType;

    std::cout << "\nEnter bus type: ";
    std::cin >> busType;
    std::cout << "\nEnter seat type: ";
    std::cin >> seatType;
    bool booked = false;
    std::vector<std::string> seating;
    for(Bus& bus : Booking::busVector){
        if(bus.busType == busType && bus.seatType == seatType){
            std::cout << "\nSeat count: ";
            std::cin >> seatCount;

            int n = bus.seats.size();
            int m = bus.seats[0].size();

            for(int k = 0; k < seatCount; k++){
                std::cout << "\nEnter seat no: ";
                std::cin >> seatNo;
                std::cout << "\nEnter gender: ";
                std::cin >> gender;
               bool place = false;
                for(int i = 0; i < n; i++){
                    for(int j = 0;j < m; j++){
                        if(seatCount > 1 && bus.seats[i][j] == seatNo)
                        {
                            bus.seats[i][j] = gender; // to be note...
                            seating.push_back(seatNo);
                            place = true;
                            booked = true;
                            break;
                        }else if(seatCount == 1 && bus.seats[i][j] == seatNo)
                        {
                            // else check for single tickets....
                            bool check = false;
                            if(bus.seats[i][j] == seatNo && gender == "F")
                            {
                                bus.seats[i][j] = gender;
                                seating.push_back(seatNo);
                                place = true;
                                booked = true;
                                check = true;
                                break;
                            }else if(bus.seats[i][j] == seatNo && gender == "M" && possible(bus.seats,"M",seatNo))
                            {
                                bus.seats[i][j] = gender;
                                seating.push_back(seatNo);
                                place = true;
                                booked = true;
                                check = true;
                                break;
                            }
                            if(check)
                            {
                                break;
                            }

                        }
                    }
                    if(place)
                    {
                        break;
                    }
                }
            }
        }
    }
    if(booked){
        std::cout << "\nBooked Successfully!!";
        Booking::ticketList[bId] = Ticket(bId, busType, seatType, cusId, seatCount,seating);
        return;
    }else{
        std::cout << "\nFemale neighboring seat!!";
        return;
    }
}
/*
        view ticket of bus
*/
void Booking::viewTicketofBus()
{
    std::string bustype;
    std::string seatType;

    std::cout << "\nBus type: ";
    std::cin >> bustype;
    std::cout << "\nSeat type: ";
    std::cin >> seatType;

    for(Bus& b : Booking::busVector)
    {
        if(b.busType == bustype && b.seatType == seatType)
        {
            int n = b.seats.size();
            int m = b.seats[0].size();
            //std::cout << "\nn: " << n;
            //std::cout << "\nm: " << m;

            std::cout << "\n*----->Driver" << std::endl;
            for(int i = 0; i < n; i++)
            {
                if(i == n/2)
                {
                    std::cout << "----->\n";
                }
                for(int j = 0; j < m; j++)
                {
                    std::cout << b.seats[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;
        }
    }
}

// std::map<int, Ticket> Booking::ticketList; // ticket List....
void Booking::summary()
{
    for(auto it = Booking::ticketList.begin(); it != Booking::ticketList.end(); it++)
    {
        Ticket t = it->second;
        std::cout << "\nBook Id: " << t.bId;
        std::cout << "\nBus type: " << t.busType;
        std::cout << "\nSeat type: " << t.seatType;
        std::cout << "\nSeat count: " << t.seatCount;
        std::cout << "\nCustomer Id: " << t.cusId;
        std::vector<std::string> seating = t.seating;
        std::cout << "\nSeating: ";
        for(auto a : seating)
        {
            std::cout << a << " ";
        }
        std::cout << "\n========================";
    }
}
void Booking::greenBusBookingPage(int cusId)
{
    bool loop = true;
    int option = 0;
    static int id = 1;
    while(loop)
    {
        greenModules();
        std::cin >> option;
        switch(option)
        {
        case 1:
            {
                // book
                int bId = id++;
                bookTicket(bId,cusId);
                break;
            }
        case 2:
            {
                // view
                viewTicketofBus();
                break;
            }
        case 3:
            {
                // cancel
                cancelTicket(cusId);
                break;
            }
        case 4:
            {
                // summary
                summary();
                break;
            }
        case 5:
            {
                // exit
                loop = false;
                break;
            }
        default:
            {
                std::cout << "Invalid Try!!" << std::endl;
                break;
            }
        }
    }

}


