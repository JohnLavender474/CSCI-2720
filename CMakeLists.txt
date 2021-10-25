cmake_minimum_required(VERSION 3.20)
project(CSCI2720_Projects)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI2720_Project1 Project1/GoAirProgram.cpp Project1/SortedList.h Project1/SortedList.cpp Project1/GoAirImplementation.cpp Project1/GoAirImplementation.h Project1/Passenger.cpp Project1/Passenger.h Project1/Flight.cpp Project1/Flight.h Project1/Node.h Project1/BookingNum.h Project1/BookingNum.cpp)
add_executable(CSCI2720_Project2 Project2/NaryTree.h Project2/T3Solver.cpp Project2/T3SolverImplementation.cpp Project2/T3SolverImplementation.h)