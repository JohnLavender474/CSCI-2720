#include "BookingNum.h"

BookingNum::BookingNum() {
    this->bookingNum = -1;
} // constructor

bool BookingNum::operator < (BookingNum & other) {
    return this->bookingNum < other.bookingNum;
} // <

bool BookingNum::operator <= (BookingNum & other) {
    return this->bookingNum <= other.bookingNum;
} // <=

bool BookingNum::operator == (BookingNum & other) {
    return this->bookingNum == other.bookingNum;
} // ==

bool BookingNum::operator > (BookingNum & other) {
    return this->bookingNum > other.bookingNum;
} // >

bool BookingNum::operator >= (BookingNum & other) {
    return this->bookingNum >= other.bookingNum;
} // >=

ostream & operator << (ostream & os, BookingNum & bookingNumObj) {
    os << bookingNumObj.bookingNum;
    return os;
} // <<
