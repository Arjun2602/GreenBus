#include "Ticket.h"
Ticket::Ticket()
:bId(0),busType(""),seatType(""),cusId(0),seatCount(0),seating()
    {

    }
Ticket::Ticket(int bId, std::string busType, std::string seatType, int cusId, int seatCount,std::vector<std::string> seating)
{
    this->bId = bId;
    this->busType = busType;
    this->seatType = seatType;
    this->cusId = cusId;
    this->seatCount = seatCount;
    this->seating = seating;
}
