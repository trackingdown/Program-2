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




int main()
{
	int user_input = 0;

	cout << "=========================================" << endl;
	cout << "1: Binary --> Decimal\n2: Decimal --> Binary" << endl;
	cout << "3: Binary --> Hexadecimal\n4: Hexadecimal --> Binary" << endl;
	cout << "Others: Quit" << endl;
	cout << "=========================================" << endl;

	cin >> user_input;

	if (user_input == 1)
	{
		bintodec();
		cout << endl;
	}
	/*
	else if (user_input == 2)
	{
		cout << dectobin()<< endl;
	}
	else if (user_input == 3)
	{
		cout << bintohex()<< endl;
	}
	else if (user_input == 4)
	{
		cout << hextobin()<< endl;
	}*/



	
	system("pause");
return 0;
}
