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
int bintodec()
{
	int user_input = 0;
	int s = 1; //used to count while moving up on the binary number list
	cout << "Enter a binary number: ";
	cin >> user_input;
	//while (

	int total = 0;

	cout << "Binary: " << user_input;

	int i = (user_input % 10);
	while (user_input > 0)
	{
		total += i * s;
		user_input = user_input / 10;
		i = (user_input % 10);
		s *= 2;

	}
	cout <<" --> Decimal: " << total << endl; 
	return total;
}

string dectobin()
{
	int user_input = 0;
	int s = 1;
	string binary = "";
	cout << "Enter a decimal number: ";
	cin >> user_input;


	if (user_input <= 128)
	{
		for (int i = 7; i != -1; i--)
		{
			s = pow(2,i);
			cout << "s = " << s << endl;
			if (user_input >= s)
			{
				user_input -= s;
				binary += "1";
			}
			else
			{
				binary += "0";
			}
			cout << "binary: " << binary << endl;

		}
	}
	/*
	while (user_input > 0)
	{
		
		if (user_input - s >= 0)
		{
			binary += "1";
		}
		else
		{
			binary +="0";
		}
		cout << binary << endl;
		user_input = user_input - s;
		cout << user_input << " after -s" << endl;

		s*=2;
	}*/
	return binary;
}




int main()
{
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


		else if (user_input == 1)
		{
			bintodec();
			cout << endl;
		}
	
		else if (user_input == 2)
		{
			cout << dectobin()<< endl;
		}
		/*
		else if (user_input == 3)
		{
			cout << bintohex()<< endl;
		}
		else if (user_input == 4)
		{
			cout << hextobin()<< endl;
		}*/
	}


	
	system("pause");
return 0;
}
