#include <iostream>
#include <string>

#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(string lastname, string firstname, int seatno, int bookingNo) {
    this->lastname = lastname;
    this->firstname = firstname;
    this->seatno = seatno;
    this->bookingNo = bookingNo;
} // Passenger constructor

Passenger::~Passenger() {}

string Passenger::getLastName() const {
    return this->lastname;
} // getLastName

string Passenger::getFirstName() const {
    return this->firstname;
} // getFirstName

int Passenger::getSeatNo() const {
    return this->seatno;
} // getSeatNo

int Passenger::getBookingNo() const {
    return this->bookingNo;
} // getBookingNo

ostream & operator << (ostream & os, const Passenger & passenger) {
    os << passenger.getLastName() << ", " << passenger.getFirstName() << " : Seat #" <<
       passenger.getSeatNo() << " Booking #" << passenger.getBookingNo() << endl;
    return os;
} // <<

bool Passenger::operator < (const Passenger & other) {
    int comp = this->lastname.compare(other.getLastName());
    return (comp == 0) ? this->firstname.compare(other.getFirstName()) < 0 : comp < 0;
} // <

bool Passenger::operator <= (const Passenger & other) {
    int comp = this->lastname.compare(other.getLastName());
    return (comp == 0) ? this->firstname.compare(other.getFirstName()) <= 0: comp <= 0;
} // <=

bool Passenger::operator > (const Passenger & other) {
    int comp = this->lastname.compare(other.getLastName());
    return (comp == 0) ? this->firstname.compare(other.getFirstName()) > 0 : comp > 0;
} // >

bool Passenger::operator >= (const Passenger & other) {
    int comp = this->lastname.compare(other.getLastName());
    return (comp == 0) ? this->firstname.compare(other.getFirstName()) >= 0 : comp >= 0;
} // >=

bool Passenger::operator == (const Passenger & other) {
    int lastnameComp = this->lastname.compare(other.getLastName());
    int firstnameComp = this->firstname.compare(other.getFirstName());
    return lastnameComp == 0 && firstnameComp == 0 && this->seatno == other.getSeatNo();
} // ==
