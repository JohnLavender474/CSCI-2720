#ifndef CSCI2720_PROJECT1_PASSENGER_H
#define CSCI2720_PROJECT1_PASSENGER_H

#include <string>

using namespace std;

class Passenger {
public:
    Passenger();
    Passenger(string lastname, string firstname, int seatno, int bookingNo);
    ~Passenger();
    string getLastName() const;
    string getFirstName() const;
    int getSeatNo() const;
    int getBookingNo() const;
    bool operator < (const Passenger & other);
    bool operator <= (const Passenger & other);
    bool operator > (const Passenger & other);
    bool operator >= (const Passenger & other);
    bool operator == (const Passenger & other);
    friend ostream & operator << (ostream & os, const Passenger & passenger);
private:
    string lastname;
    string firstname;
    int seatno;
    int bookingNo;
}; // Passenger

#endif //CSCI2720_PROJECT1_PASSENGER_H
