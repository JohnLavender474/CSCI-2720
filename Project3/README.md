# CSCI2720_Project3

John Lavender 

https://github.com/JohnLavender474/CSCI2720_Projects

To launch the program, enter 'make clean', then 'make', and then './P3Executable'. The following prompt will appear:

     avl / hashmap: 

This is the "main hub" of the program. You may enter either "avl" or "hashmap". All input in this program is NOT case or
space sensitive, so all of the following inputs are valid for this prompt (and describe acceptable formats for all other
prompts going forward in the program):

     avl
     a vl 
     AvL
     A vL
     a V l
     hashmap
     has H mAp
     hAShmA P

Whether you enter "avl" or "hashmap", the program will then ask for a file path.

     Enter file path:

The file path must be relative to the directory of the running program. An example:

     Enter file path: ./test/input1.txt

When you enter the file path, the integer-string pairs of the file will be displayed followed by a list of the valid
commands available. The list of commands is different depending on whether you chose "avl" or "hashmap" at the first
prompt. You may enter
"return" to go back to the main hub or "exit" to exit the program entirely.

The following is an example of what you might see at this point.

     avl / hashmap: avl
     Enter file path: ./test/input1.txt

     39 BALMY
     12 ALLOT
     73 DRONE
     10 ADIEU
     27 ARISE
     83 FACES
     45 BRISK
     57 CACTI
     43 BLAST
     49 CACHE

     AVL VALID COMMANDS:
     insert
          program will ask for integer key
          program will ask for string value
     remove
          program will ask for integer key
     contains
          program will ask for integer key
     get
          program will ask for integer key
     print
          program will ask for print type:
     preorder
     postorder
     levelorder
     inorder
     size
     height
     clear
     return (return to main hub)
     help (will print these instructions)

     AVL_TREE ------------------------------------------------------------------
     Command: 

Inserting two new integer-string pairs, performing levelorder print, removing integer-string pair with key = 39,
checking if avl tree contains integer-string pair with key = 45, fetching value from integer-string pair with key = 83,
clearing the avl tree and then returning to main hub.

     AVL_TREE ------------------------------------------------------------------
     Command: insert
     Integer key: 13
     String value: HELLO

     AVL_TREE ------------------------------------------------------------------
     Command: insert
     Integer Key: 14
     String Value: WORLD

     AVL_TREE ------------------------------------------------------------------
     Command: print
     Print type: levelorder

     Performing levelorder function...
     (39, BALMY)
     (12, ALLOT)
     (57, CACTI)
     (10, ADIEU)
     (14, WORLD)
     (45, BRISK)
     (73, DRONE)
     (13, HELLO)
     (27, ARISE)
     (43, BLAST)
     (49, CACHE)
     (83, FACES)

     AVL_TREE ------------------------------------------------------------------
     Command: remove
     Integer Key: 39

     AVL_TREE ------------------------------------------------------------------
     Command: contains
     Integer Key: 45
     (43, BLAST)
     (57, CACTI)
     (45, BRISK)
     True

     AVL_TREE ------------------------------------------------------------------
     Command: get
     Integer Key: 83
     (43, BLAST)
     (57, CACTI)
     (73, DRONE)
     (83, FACES)
     Found value: FACES

     AVL_TREE ------------------------------------------------------------------
     Command: clear

     Successfully cleared avl tree.


     AVL_TREE ------------------------------------------------------------------
     Command: return
     Returning to main hub...
     avl / hashmap:

Working with "hashmap" is nearly identical to working with "avl". Differences are minor, such as "insert" in "avl" being
replaced with "put" in hashmap. In "avl", attempting to insert an integer-value pair where the integer key already
exists in the tree will result in the value of that particular node being overwritten by the new value. (This is the
expected behavior since of course there cannot be duplicate keys in an avl tree.) This same behavior occurs when working
with "hashmap" "put".

KNOWN ERROR:
When the program prompts for a file to be entered, entering a nonexistent file or a bad directory does not result in an
error message. Instead, the screen is cleared and the program returns to the "avl / hashmap: " prompt.
