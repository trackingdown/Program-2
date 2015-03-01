//Course: CS215-005
//Assignment: Program 2
//Date: 2/22/15
//Purpose: To create a four-function program that will ask the user to select 
//		from operations until they quit
//Author: Nicholas Pfister

#include <cmath>
#include <string>
#include <iostream>

using namespace std;


//converts binary numbers to decimal numbers
long long bintodec()
{
	long long user_input = 0; //"long long" is used to increase size of 'long'
		//so that if a user enters a very large binary the program will not quit.

	cout << "Enter a binary number: ";
	cin >> user_input;
	bool invalid = true; //used to end the loop if the second if statement executes.
	int digit_test = user_input % 10; //digit_test is used to test each individual 
		//number to see if any are invalid.
	long long input_copy = user_input; //input_copy is simply a carbon copy of the 
		//original user_input so it is not modified during testing.
	while (digit_test > 1 || digit_test < 0 || invalid != false)
	{
		if ((digit_test > 1) || (digit_test < 0))
		{
			cout << "Input contains an invalid digit." << endl;
			return user_input;
		}
		input_copy /= 10;
		digit_test = input_copy % 10;
		if (input_copy == 0)
		{
			invalid = false;
		}

	}


	long long decimal = 0; //the final decimal value.

	cout << "Binary: " << user_input;

	int s = 1; //used to count while moving up on the binary number list.

	long long i = (user_input % 10); //if the number is 1, it will add a positive number
		//when multiplied by s if the number is 0, nothing will be added.


	while (user_input > 0)
	{
		decimal += i * s;
		user_input = user_input / 10;
		i = (user_input % 10);
		s *= 2; //increasing by x2 each time to go by the correct values (1, 2, 4, 8, etc).
	}
	cout <<" --> Decimal: " << decimal << endl; 
	return decimal;
}

string dectobin()
{
	long long user_input = 0;
	string binary = "";
	cout << "Enter a decimal number: ";
	cin >> user_input;

	if (user_input < 0)
	{
		cout << "Input is invalid." << endl;
		return binary;
	}

	cout << "Decimal: "<< user_input;
		
	int s = 1;
	if (user_input <= 255)//if the input is exactly 256, the program encounters an
		//error in which it will display "11111111"
		//this is fixed by simply running for one digit less
		//this also allows for a total of 8 decimals, regardless of value under 256.
	{
		for (int i = 7; i != -1; i--)
		{
			s = pow(2,i);
			if (user_input >= s)
			{
				user_input -= s;
				binary += "1";
			}
			else
			{
				binary += "0";
			}

		}
	}
	else
	{ //this statement will run if the decimal is 256 or any larger
		int i = 0;
		//this loop increases the value of s until it is larger than the input,
		//so that the conversion can be worked from the top to the bottom
		while (s < user_input)
		{
			s = pow(2,i);
			i++;
		}
		i--;//i is decreased by 1 so when 2^i is ran, the value will be lower than input
		
		//this statement runs just for a safe measure of the program not detecting
		//that s > user_input
		//it will decrease s one time so that way it is less than user_input
		if (s > user_input)
		{
			s /= 2;
		}
		//s decreases until 0, adding binary digits depending on size of user_input
		for (s > 0; i--;)
		{
			
			if (user_input >= s)
			{
				user_input -= s;
				binary += "1";
			}
			else
			{
				binary += "0";
			}
			s /= 2;
		}
	
	}
	
	cout << " --> Binary: " << binary << endl;
	return binary;
}

string bintohex()
{
	long long user_input = 0;
	int s = 1; //used to count while moving up on the binary number list
	cout << "Enter a binary number: ";
	cin >> user_input;
	string hex;
	bool invalid = true;
	int digit_test = user_input % 10; //digit_test for testing each individual number
		//for invalid input
	long long input_copy = user_input;//a carbon copy of user_input so the original
		//values can still be used but not modified
	while (digit_test > 1 || digit_test < 0 || invalid != false)
	{
		if ((digit_test > 1) || (digit_test < 0))
		{
			cout << "Input contains an invalid digit." << endl;
			return hex;
		}
		input_copy /= 10;
		digit_test = input_copy % 10;
		if (input_copy == 0)
		{
			invalid = false;
		}

	}

	long long decimal = 0;
	
	cout << "Binary: " << user_input;

	long long i = (user_input % 10);
	while (user_input > 0)
	{
		long long decimal = 0;
		int s = 1;
		//this loop runs through the first four binary digits at the very end of the input
		//and then stops
		for (int w = 0; w <= 3; w++)
		{
			decimal += i * s;
			user_input /= 10;
			//since user_input is decreasing, after the fourth loop it will be four digits smaller
			i = (user_input % 10);
			s *= 2;
		}
		//this loop runs only one time and goes through each number from 15 down 
		//to 0, and adds the corresponding 4-decimal hexidecimal value until 
		for (int w = 0; w < 1; w++)
		{
			if (decimal == 15)
			{
				hex += "F";
			}
			else if (decimal == 14)
			{
				hex += "E";
			}
			else if (decimal == 13)
			{
				hex += "D";
			}
			else if (decimal == 12)
			{
				hex += "C";
			}
			else if (decimal == 11)
			{
				hex += "B";
			}
			else if (decimal == 10)
			{
				hex += "A";
			}
			else if (decimal == 9)
			{
				hex += "9";
			}
			else if (decimal == 8)
			{
				hex += "8";
			}
			else if (decimal == 7)
			{
				hex += "7";
			}
			else if (decimal == 6)
			{
				hex += "6";
			}
			else if (decimal == 5)
			{
				hex += "5";
			}
			else if (decimal == 4)
			{
				hex += "4";
			}
			else if (decimal == 3)
			{
				hex += "3";
			}
			else if (decimal == 2)
			{
				hex += "2";
			}
			else if (decimal == 1)
			{
				hex += "1";
			}
			else if (decimal == 0)
			{
				hex = hex;
			}
		}
	}
	string new_hex;
	for (int s = (hex.length() - 1);s >= 0;)
	{
		new_hex += hex.substr(s, 1);
		s--;
	}
	cout << " --> Hexadecimal: " << new_hex << endl;

return new_hex;
}


string hextobin()
{
	string F = "1111";
	string E = "1110";
	string D = "1101";
	string C = "1100";
	string B = "1011";
	string A = "1010";

	string user_input;
	int s = 0;
	cout << "Enter a hexicedcimal number: ";
	cin >> user_input;
	
	cout << "Hexadecimal: " << user_input;

	//the final binary output
	string binary;
	
	string w;
	int n = user_input.length();
	for (int i = 0; i < n;)
	{
		//grabs whatever value is selected and checks which value will be added to binary
		w = user_input.substr(i,1);

		i++;
		if (w == "0")
		{
			binary += "0000";
		}
		else if (w == "1")
		{
			binary += "0001";
		}
		else if (w == "2")
		{
			binary += "0010";
		}
		else if (w == "3")
		{
			binary += "0010";
		}
		else if (w == "4")
		{
			binary += "0100";
		}
		else if (w == "5")
		{
			binary += "0101";
		}

		else if (w == "6")
		{
			binary += "0110";
		}
		else if (w == "7")
		{
			binary += "0111";
		}
		else if (w == "8")
		{
			binary += "1000";
		}
		else if (w == "9")
		{
			binary += "1001";
		}
		else if (w == "A" || w == "a")
		{
			binary += A;
		}
		else if (w == "B" || w == "b")
		{
			binary += B;
		}
		else if (w == "C" || w == "c")
		{
			binary += C;
		}
		else if (w == "D" || w == "d")
		{
			binary += D;
		}
		else if (w == "E" || w == "e")
		{
			binary += E;
		}
		else if (w == "F" || w == "f")
		{
			binary += F;
		}
	
	}
	cout << " --> Hexadecimal: " << binary << endl;
return w;
}


void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}
	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}


int main()
{
	//bool will end loop when non-integer character is input
	bool more = true;
	while (more)
	{

		int user_input = 0;

		cout << "=========================================" << endl;
		cout << "1: Binary --> Decimal\n2: Decimal --> Binary" << endl;
		cout << "3: Binary --> Hexadecimal\n4: Hexadecimal --> Binary" << endl;
		cout << "Others: Quit" << endl;
		cout << "=========================================" << endl;

		cin >> user_input;
		
		if (cin.fail())
		{
			more = false;
			cout << "Thank you for using this program." << endl;
		}
		else if (user_input > 4 || user_input < 1)
		{
			cout << "Invalid selection. Please try again. " << endl;
		}
		else if (user_input == 1)
		{
			bintodec();
			cout << endl;
		}
	
		else if (user_input == 2)
		{
			dectobin();
			cout << endl;
		}
		
		else if (user_input == 3)
		{
			bintohex();
			cout << endl;
		}
		
		else if (user_input == 4)
		{
			hextobin();
			cout << endl;
		}
	}


	pause_215(more);
	//function required parameters, however unsure of what input is required, as it
	//was not specified
	//placed bool into the function, however skips "press enter to continue" prompt
	//unsure of how to fix
return 0;
}