#  CSCI2720_Project2

John Lavender UGA ID # 811045788

To launch the program, enter "make" and "./T3Solver".
The user will be prompted to enter a valid serialized game board
composed of X's, O's, and asterisks (to designate blanks).

Examples:

    "**X*OX*OX"
    "***XXO***"
    "*********"

Afterwards, the user will be prompted to enter the type of traversal
to be performed. The following are valid inputs.

    "levelorder"
    "preorder"
    "postorder"
    "linked preorder"
    "linked postorder"

The commands "linked preorder" and "linked postorder" utilize a 
linked-inversion algorithm for traversal. This method of traversal
is significantly faster than the other traversals. (Preorder and postorder
traversals are done recursively. Levelorder is done iteratively.)

The user may continue to try out the different traversals infinitely.
To view the results of a game board, the user may enter "results".
To begin again with a new game board, the user may enter "restart" at
any prompt. To exit the program, the user may enter "exit".

