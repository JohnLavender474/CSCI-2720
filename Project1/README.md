# CSCI2720_Project1

John Lavender 

To launch the program, simply run "make" and then "./GoAirProgram". The program begins by displaying all of the
available commands followed by a command prompt. I will now demonstrate a test run.

Available commands:
af -flightno -- Add flight rf -flightno -- Remove flight ap -flightno -lastname -firstname -seatno -- Add passenger rp
-flightno -lastname -firstname -seatno -- Remove passenger sp -flightno -lastname -firstname -seatno -- Show passenger
sap -flightno -- Show all passengers snp -flightno -num -- Show newest passengers sfp -flightno -num -- Show first
passengers saf -- Show all flights safap -- Show all flights and passengers commands -- Print this list of commands exit
-- Exit this program

To begin with, we will need to insert a new flight with a correspond flight no. We'll make the flight no be 1.

    Command: af 1

Next, we will add a couple of passengers:

    Command: ap 1 Lavender John 1
    Command: ap 1 Prashant Doshi 2
    Command: ap 1 Kong Donkey 3
    Command: ap 1 Mario Super 4
    Command: ap 1 Falcon Captain 5
    Command: ap 1 Dylan Bob 6
    Command: ap 1 Racer Rad 7

Next, we'll display all of the info for these passengers.

    Command: sap 1

Next, we can delete one or two of these passengers.

    Command: rp 1 Kong Donkey 3
    Command: rp 1 Falcon Captain 5

Now let's show the first 3 and last 3 passengers who were added:

    Command: sfp 1 3
    
       Lavender, John : Seat #1 Booking #1
       Prashant, Doshi : Seat #2 Booking #2
       Mario, Super : Seat #4 Booking #4
       
    Command: snp 1 3
    
       Racer, Rad : Seat #7 Booking #7
       Dylan, Bob : Seat #6 Booking #6
       Mario, Super : Seat #4 Booking #4

Let's add Donkey Kong and Captain Falcon to a different flight!

    Command: af 2
    Command: ap 2 Kong Donkey 1
    Command: ap 2 Falcon Captain 2

Let's display all flights and passengers:

    Command: safap
    
      Flight No: 1
         Dylan, Bob : Seat #6 Booking #6
         Lavender, John : Seat #1 Booking #1
         Mario, Super : Seat #4 Booking #4
         Prashant, Doshi : Seat #2 Booking #2
         Racer, Rad : Seat #7 Booking #7

      Flight No: 2
         Falcon, Captain : Seat #2 Booking #2
         Kong, Donkey : Seat #1 Booking #1

That's the end of the basics for using this program!

Please note that some of the commands give no response to faulty input while others will throw an exception. Exceptions
are thrown by the SortedList class and can be caught and handled.
       
