cmake_minimum_required(VERSION 3.20)
project(CSCI2720_Projects)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI2720_Project1 Project1/GoAirProgram.cpp Project1/SortedList.h Project1/SortedList.cpp Project1/GoAirImplementation.cpp Project1/GoAirImplementation.h Project1/Passenger.cpp Project1/Passenger.h Project1/Flight.cpp Project1/Flight.h Project1/Node.h Project1/BookingNum.h Project1/BookingNum.cpp Project4/hdr/SortedArrayMap.h)
add_executable(CSCI2720_Project2 Project2/NaryTree.h Project2/T3Solver.cpp Project2/T3SolverImplementation.cpp Project2/T3SolverImplementation.h)
add_executable(CSCI2720_Project3 Project3/hdr/Function.h Project3/hdr/AVL_Node.h Project3/hdr/AVL_Tree.h Project3/hdr/Comparable.h Project3/hdr/String.h Project3/hdr/Integer.h Project3/P3Executable.cpp)
add_executable(CSCI2720_Project4 Project4/hdr/Graph.h Project4/hdr/Comparable.h Project4/hdr/Pair.h Project4/hdr/SortedArray.h Project4/main.cpp Project4/hdr/Vertex.h Project4/hdr/Iterator.h)