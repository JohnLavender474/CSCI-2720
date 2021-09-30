cmake_minimum_required(VERSION 3.20)
project(CSCI2720_Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI2720_Project1 GoAirProgram.cpp SortedList.h SortedList.cpp GoAirImplementation.cpp GoAirImplementation.h Passenger.cpp Passenger.h Flight.cpp Flight.h Node.h BookingNum.h BookingNum.cpp)
