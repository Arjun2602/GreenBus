#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include <map>
#include <string>
#include <vector>

class Ticket
{
public:
    int bId;
    std::string busType;
    std::string seatType;
    int cusId;
    int seatCount;
    std::vector<std::string> seating;
    Ticket();
    Ticket(int bId, std::string busType, std::string seatType, int cusId, int seatCount,std::vector<std::string> seating);
};

#endif // TICKET_H_INCLUDED
