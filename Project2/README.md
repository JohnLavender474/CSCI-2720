#  CSCI2720_Project2

John Lavender # UGA ID 811045788

https://github.com/JohnLavender474/CSCI2720_Projects/tree/master/Project2

To launch the program, enter "make clean", then "make", and then "./T3Solver".
The user will be prompted to enter a valid serialized game board
composed of X's, O's, and asterisks (to designate blanks).

Examples:

    "**X*OX*OX"
    "***XXO***"
    "X***OO**X*"

If the number of O's is not equal to or one less than the number of X's,
an error message will be displayed and the user will able to try again.

After that, the user be will be prompted to either use the traversal
options or else play against. The following are valid inputs at this points:

    "traversal"
    "play"
    "restart"
    "exit"

If the user chooses to use the traversal options, the user will then
be prompted to enter the type of traversal to be performed. The user
will also have the option to see the results (the number of wins for
X and O and the size of the trees) and to see the output of a branch
from the root to a random leaf. The following are valid inputs here:

    "levelorder"
    "preorder"
    "postorder"
    "linked inversion preorder"
    "linked inversion postorder"
    "results"
    "random branch"
    "restart"
    "exit"

The command "random branch" is my solution to question 2 of the project.
The commands "linked inversion preorder" and "linked inversion postorder"
are my solutions to the bonus question of the project.

If the user instead chooses to play against the AI, then he will be 
prompted to enter which player he would like to play as:

    "X"
    "O"

The player and AI will take turns makings moves. The player will enter
a row and column input for each move. (The commands "restart" and "exit"
will not work for the duration of gameplay.)

_________________________________

IMPORTANT NOTE:

There are various points where system("clear") is called in the code.
After the user has entered a serialized game board, the program will 
begin loading all of the nodes in the tree. A prompt with the following
format will be shown on screen:

    loading nodes...
    nodes loaded so far: x

After this prompt is displayed, system("clear") is called and the same
prompt is displayed again but with the value of x updated. If system("clear")
is not compatible with the terminal environment being used, then it may
appear as if the program has gone into an infinite loop of print statements,
especially if a game board with many blanks has been entered.

_________________________________

KNOWN ISSUE: 

There is an occasional glitch when using the traversal methods that
will cause some node pointers to be overwritten with garbage values.
This causes the entire traversal functionality to be unusable and requires
either "restart" or "exit". This glitch does not occur often at all. It is
(hopefully) unlikely that it will occur while this project is being graded.
The cause of the issue is unknown as of yet.

_________________________________

P.S. BEWARE of entering the blank game board "*********"!
You'll be sitting, waiting a long while for all the nodes to load, lol!