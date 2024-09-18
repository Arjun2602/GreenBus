#include "Bus.h"

Bus::Bus(std::string busType, std::string seatType)
{
    this->busType = busType;
    this->seatType = seatType;
    this->seats = std::vector<std::vector<std::string>>(4,std::vector<std::string>(3));
    createSeats(seats);
}

void Bus::createSeats(std::vector<std::vector<std::string>>& seats)
{
    int n = seats.size();
    int m = seats[0].size();
    int number = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::stringstream ss;
            ss << number;
            std::string s = ss.str();
            seats[i][j] = s;
            number++;

        }
    }
}


