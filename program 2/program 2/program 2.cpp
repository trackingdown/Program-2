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

	int decimal = 0;

	cout << "Binary: " << user_input;

	int i = (user_input % 10);
	while (user_input > 0)
	{
		decimal += i * s;
		user_input = user_input / 10;
		i = (user_input % 10);
		s *= 2;

	}
	cout <<" --> Decimal: " << decimal << endl; 
	return decimal;
}

string dectobin()
{
	int user_input = 0;
	int s = 1;
	string binary = "";
	cout << "Enter a decimal number: ";
	cin >> user_input;

	cout << "Decimal: "<< user_input;

	if (user_input <= 255)
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
	else
	{
		int i = 0;
		while (s < user_input)
		{
			s = pow(2,i);
			i++;
		}
		i--;
		if (s > user_input)
		{
			s /= 2;
		}

		for (s > -1; i--;)
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
	
	cout << " --> Binary: " << binary << endl;
	}

	return binary;
}

int bintohex()
{
	int user_input = 0;
	int s = 1; //used to count while moving up on the binary number list
	cout << "Enter a binary number: ";
	cin >> user_input;

	int decimal = 0;
	cout << "Binary: " << user_input;

	int i = (user_input % 10);
	while (user_input > 0)
	{
		decimal += i * s;
		user_input = user_input / 10;
		i = (user_input % 10);
		s *= 2;
	}
	string F = "1111";
	string f = "1111";
	string E = "1110";
	string e = "1110";
	string D = "1101";
	string d = "1101";
	string C = "1100";
	string c = "1100";
	string B = "1011";
	string b = "1011";
	string A = "1010";
	string a = "1010";


	string hex = "";
	while (decimal >= A)
	{
		if (decimal >= F)
		{
			decimal -= F;
			hex += "F";
		}
		if (decimal >= E)
		{
			decimal -= E;
			hex += "E";
		}
		if (decimal >= D)
		{
			decimal -= D;
			hex += "D";
		}
		if (decimal >= C)
		{
			decimal -= C;
			hex += "C";
		}
		if (decimal >= B)
		{
			decimal -= B;
			hex += "B";
		}
		if (decimal >= A)
		{
			decimal -= A;
			hex += "A";
		}

	}
	cout << " --> Hexadecimal: ";
	if (decimal > 0)
	{
		cout << decimal;
	}
	cout << hex << endl;


return decimal;
}


string hextobin()
{
	string F = "1111";
	string f = "1111";
	string E = "1110";
	string e = "1110";
	string D = "1101";
	string d = "1101";
	string C = "1100";
	string c = "1100";
	string B = "1011";
	string b = "1011";
	string A = "1010";
	string a = "1010";

	string user_input;
	int s = 0;
	cout << "Enter a hexicedcimal number: " << endl;
	cin >> user_input;
	
	cout << "Hexadecimal: " << user_input;

	string hex;
	//need to split to ints from the string variables somehow
	
	string w;
	int n = user_input.length();
	for (int i = 0; i < n;)
	{
		w = user_input.substr(i,1);

		i++;
		if (w == "0")
		{
			hex += "0000";
		}
		else if (w == "1")
		{
			hex += "0001";
		}
		else if (w == "2")
		{
			hex += "0010";
		}
		else if (w == "3")
		{
			hex += "0010";
		}
		else if (w == "4")
		{
			hex += "0100";
		}
		else if (w == "5")
		{
			hex += "0101";
		}

		else if (w == "6")
		{
			hex += "0110";
		}
		else if (w == "7")
		{
			hex += "0111";
		}
		else if (w == "8")
		{
			hex += "1000";
		}
		else if (w == "9")
		{
			hex += "1001";
		}
		else if (w == "A" || w == "a")
		{
			hex += A;
		}
		else if (w == "B" || w == "b")
		{
			hex += B;
		}
		else if (w == "C" || w == "c")
		{
			hex += C;
		}
		else if (w == "D" || w == "d")
		{
			hex += D;
		}
		else if (w == "E" || w == "e")
		{
			hex += E;
		}
		else if (w == "F" || w == "f")
		{
			hex += F;
		}
	
	}
	cout << " --> Hexadecimal: " << hex << endl;
return w;
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


	
	system("pause");
return 0;
}