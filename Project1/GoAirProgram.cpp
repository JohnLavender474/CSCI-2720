#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

#include "GoAirImplementation.h"

using namespace std;

void goAirProgram();

void handleCommand(vector<string> &tokens, string &msg);

void tokenize(string &str, vector<string> &tokens);

bool isAlphaNum(string &str);

bool isAlpha(string &str);

bool isNum(string &str, int &num);

void printCommands();

void printWelcome();

void test();

const string af = "af";
const string rf = "rf";
const string ap = "ap";
const string rp = "rp";
const string sp = "sp";
const string sap = "sap";
const string snp = "snp";
const string sfp = "sfp";
const string saf = "saf";
const string safap = "safap";
const string commands = "commands";
const string exitProgram = "exit";

string const afSuccess = "Successfully added flight";
string const rfSuccess = "Successfully removed flight";
string const apSuccess = "Successfully added passenger";
string const rpSuccess = "Successfully removed passenger";

const string afErrorMsg = "Failed to add flight no ";
const string rfErrorMsg = "Failed to remove flight no ";
const string apErrorMsg = "Failed to add passenger to flight no ";
const string rpErrorMsg = "Failed to remove passenger from flight no ";
const string spErrorMsg = "Failed to show passenger on flight no ";
const string sapErrorMsg = "Failed to show all passengers on flight no ";
const string snpErrorMsg = "Failed to show newest passengers on flight no";
const string sfpErrorMsg = "Failed to show first passengers on flight no";

GoAirImplementation *goAir = new GoAirImplementation();

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		string arg = argv[1];
		if (arg.compare("test") == 0)
		{
			test();
			return 0;
		}
	}
	printWelcome();
	goAirProgram();
	return 0;
}

void goAirProgram()
{
	string input;
	vector<string> tokens;
	while (1)
	{
		cout << endl;
		input = "";
		tokens.clear();
		do
		{
			cout << "Command: ";
			getline(cin, input);
		}
		while (!(isAlphaNum(input)) || input.empty());
		tokenize(input, tokens);
		if (tokens.at(0) == exitProgram)
		{
			cout << "\nThank you for using the Go Air Airlines module!\n" << endl;
			break;
		}
		string msg = "";
		handleCommand(tokens, msg);
		cout << "   " << msg << endl;
	}
}

void handleCommand(vector<string> &tokens, string &msg)
{
	cout << endl;
	int flightno;
	string firstname;
	string lastname;
	int seatno;
	if (tokens.at(0)
			    .compare(commands) == 0)
	{
		printCommands();
	}
	else if (tokens.at(0)
			         .compare(af) == 0)
	{
		if (isNum(tokens.at(1), flightno))
		{
			if (flightno != -1)
			{
				goAir->addFlight(flightno);
				msg = afSuccess;
			}
			else
			{
				msg = afErrorMsg;
			}
		}
	}
	else if (tokens.at(0)
			         .compare(rf) == 0)
	{
		if (isNum(tokens.at(1), flightno))
		{
			if (flightno != -1)
			{
				goAir->removeFlight(flightno);
				msg = rfSuccess;
			}
			else
			{
				msg = rfErrorMsg;
			}
		}
	}
	else if (tokens.at(0)
			         .compare(ap) == 0)
	{
		if (tokens.size() != 5)
		{
			cout << apErrorMsg << endl;
		}
		else if (isNum(tokens.at(1), flightno) && isAlpha(tokens.at(2)) &&
		         isAlpha(tokens.at(3)) && isNum(tokens.at(4), seatno))
		{
			lastname = tokens.at(2);
			firstname = tokens.at(3);
			if (flightno != -1 && seatno != -1)
			{
				goAir->addPassenger(flightno, lastname, firstname, seatno);
				msg = apSuccess;
			}
			else
			{
				msg = spErrorMsg;
			}
		}
	}
	else if (tokens.at(0)
			         .compare(rp) == 0)
	{
		if (tokens.size() != 5)
		{
			cout << rpErrorMsg << endl;
		}
		else if (isNum(tokens.at(1), flightno) && isAlpha(tokens.at(2)) &&
		         isAlpha(tokens.at(3)) && isNum(tokens.at(4), seatno))
		{
			lastname = tokens.at(2);
			firstname = tokens.at(3);
			if (flightno != -1 && seatno != -1)
			{
				goAir->removePassenger(flightno, lastname, firstname, seatno);
				msg = rpSuccess;
			}
			else
			{
				msg = rpErrorMsg;
			}
		}
	}
	else if (tokens.at(0)
			         .compare(sp) == 0)
	{
		if (tokens.size() != 5)
		{
			cout << spErrorMsg << endl;
		}
		else if (isNum(tokens.at(1), flightno) && isAlpha(tokens.at(2)) &&
		         isAlpha(tokens.at(3)) && isNum(tokens.at(4), seatno))
		{
			lastname = tokens.at(2);
			firstname = tokens.at(3);
			if (flightno != -1 && seatno != -1)
			{
				goAir->showPassenger(flightno, lastname, firstname, seatno);
			}
			else
			{
				msg = spErrorMsg;
			}
		}
	}
	else if (tokens.at(0)
			         .compare(saf) == 0)
	{
		goAir->showAllFlights();
	}
	else if (tokens.at(0)
			         .compare(sap) == 0)
	{
		if (tokens.size() != 2)
		{
			msg = sapErrorMsg;
		}
		else
		{
			if (isNum(tokens.at(1), flightno))
			{
				if (flightno != -1)
				{
					cout << endl;
					goAir->showAllPassengers(flightno);
				}
				else
				{
					msg = sapErrorMsg;
				}
			}
		}
	}
	else if (tokens.at(0)
			         .compare(snp) == 0)
	{
		if (tokens.size() != 3)
		{
			msg = snpErrorMsg;
		}
		else
		{
			int k;
			if (isNum(tokens.at(1), flightno) && isNum(tokens.at(2), k))
			{
				if (flightno != -1 && k != -1)
				{
					goAir->showNewPassengers(flightno, k);
				}
				else
				{
					msg = snpErrorMsg;
				}
			}
		}
	}
	else if (tokens.at(0)
			         .compare(sfp) == 0)
	{
		if (tokens.size() != 3)
		{
			msg = sfpErrorMsg;
		}
		else
		{
			int k;
			if (isNum(tokens.at(1), flightno) && isNum(tokens.at(2), k))
			{
				if (flightno != -1 && k != -1)
				{
					goAir->showFirstPassengers(flightno, k);
				}
				else
				{
					msg = sfpErrorMsg;
				}
			}
		}
	}
	else if (tokens.at(0)
			         .compare(safap) == 0)
	{
		goAir->showAllFlightsAndPassengers();
	}
}

void tokenize(string &str, vector<string> &tokens)
{
	string temp = "";
	for (int i = 0;
	     i < str.length();
	     i++)
	{
		if (str[i] == ' ')
		{
			if (!temp.empty())
			{
				tokens.push_back(temp);
			} // if
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}
	tokens.push_back(temp);
} // tokenize

bool isAlphaNum(string &str)
{
	for (int i = 0;
	     i < str.size();
	     i++)
	{
		if (!isalnum(str[i]) && str[i] != ' ')
		{
			return false;
		}
	}
	return true;
}

bool isAlpha(string &str)
{
	for (int i = 0;
	     i < str.size();
	     i++)
	{
		if (!isalpha(str[i]) && str[i] != ' ')
		{
			return false;
		}
	}
	return true;
}

bool isNum(string &str, int &num)
{
	for (int i = 0;
	     i < str.size();
	     i++)
	{
		if (!isnumber(str[i]) && str[i] != ' ')
		{
			num = -1;
			return false;
		}
	}
	num = atoi(str.c_str());
	return true;
}

void printCommands()
{
	cout << "\n\tAvailable commands:" << endl;
	int x = 400;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\taf -flightno -- Add flight" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\trf -flightno -- Remove flight" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tap -flightno -lastname -firstname -seatno -- Add passenger" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\trp -flightno -lastname -firstname -seatno -- Remove passenger" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tsp -flightno -lastname -firstname -seatno -- Show passenger" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tsap -flightno -- Show all passengers" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tsnp -flightno -num -- Show newest passengers" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tsfp -flightno -num -- Show first passengers" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tsaf -- Show all flights" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tsafap -- Show all flights and passengers" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\tcommands -- Print this list of commands" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\t\texit -- Exit this program" << endl;
	cout << endl;
}

void printWelcome()
{
	int x = 600;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\n   GO AIR AIRLINES\n" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << "\tWelcome to the GoAir Airlines module." << endl;
	cout << "\tHere you can view all flight and passenger info logged into our system" << endl;
	this_thread::sleep_for(chrono::milliseconds(x));
	printCommands();
}

void test()
{
	goAir->addFlight(11);
	goAir->addPassenger(11, "Lavender", "John", 11);
	goAir->addPassenger(11, "Doshi", "Prashant", 1);
	goAir->addPassenger(11, "Kong", "Donkey", 3);
	goAir->addPassenger(11, "Mario", "Super", 4);
	goAir->addPassenger(11, "Cheese", "Big", 13);
	goAir->addPassenger(11, "Mac", "Big", 14);
	cout << "\nShow all flights And Passengers" << endl;
	goAir->showAllFlightsAndPassengers();
	cout << "\nShow newest 4 passengers" << endl;
	goAir->showNewPassengers(11, 4);
	cout << "\nShow first 4 passengers" << endl;
	goAir->showFirstPassengers(11, 4);
	goAir->removePassenger(11, "Kong", "Donkey", 3);
	goAir->removePassenger(11, "Doshi", "Prashant", 1);
	cout << "\nShow newest 4 passengers after removing Kong and Doshi" << endl;
	goAir->showNewPassengers(11, 4);
	cout << "\nShow first 4 passengers" << endl;
	goAir->showFirstPassengers(11, 4);
	goAir->showAllFlightsAndPassengers();
	goAir->removePassenger(11, "Lavender", "John", 11);
	cout << "\nShow all flights and passengers again" << endl;
	goAir->showAllFlightsAndPassengers();
	cout << "\nShow newest 3 passengers after also deleting Mario" << endl;
	goAir->showNewPassengers(11, 3);
	cout << "\nShow first 3 passengers" << endl;
	goAir->showFirstPassengers(11, 3);
}