# CSCI_Project4

John Lavender # UGA ID: 811045788

https://github.com/JohnLavender474/CSCI2720_Projects

To start the program, enter 'make clean', 'make', and './US_Graph_Program'.
A list of available command prompts will appear. Each command is associated with an int.

At the 'Command: ' prompt:
    
    0. exit the program
    
    1. print the help text

    2. clear the screen

    3. print the contiguity list of a state

    4. print the contiguity count of a state

    5. print the states with contiguity count that matches your input

    6. print the (first found) state with the highest contiguity state

    7. print the shortest path from one state to another

    8. print the shortest path tree of a state

Let's find the list of states contiguous to AR:

    Command: 3

    enter state (abbreviation): a R

    /* state input is not case or whitespace sensitive */

    CONTIGUOUS STATES:
        LA
        MO
        MS
        OK
        TN
        TX

Now let's find the contiguity count of CA:

    Command: 4

    enter state (abbreviation): ca

    NUMBER OF STATES CONTIGUOUS TO CA: 3

And now let's find all the states that have contiguity count of 1:

    Command: 5

    enter int: 1

    VERTEX: ME
        EDGE 1: NH

Okay, so what's the shortest path from GA to WA?

    Command: 7

    prompt for entering start state...
    enter state (abbreviation): G  a

    prompt for entering start state...
    enter state (abbreviation): wA

        GA -->
        TN -->
        MO -->
        NE -->
        WY -->
        ID -->
        WA

Commands 5 and 8 are, respectively, for finding the state with 
the highest contiguity count and for printing the shortest path tree
of a state.



No known issues with the program.