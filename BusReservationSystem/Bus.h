#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
#include <string>
#include <sstream>
#include <vector>

class Bus
{
public:
    std::string busType;
    std::string seatType;
    std::vector<std::vector<std::string>> seats;

    Bus();
    Bus(std::string busType, std::string seatType);

    void createSeats(std::vector<std::vector<std::string>>& seats);

};

#endif // BUS_H_INCLUDED
