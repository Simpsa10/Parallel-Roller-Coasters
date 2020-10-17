/*This program will implement Horner's method of computing a modulo. It will ask the user to enter
   a numerator and a denominator. It will then output the value of the remainder. */

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Horner 
	{
	private:
		string n;
		int m, len, asci, rem;

	public:
		Horner()
			{
			rem = 0;
			}
		
		void values()
			{
			cout << "Numerator:";
			cin >> n;
			cout << "Denominator:";
			cin >> m;
			}

		int length()
			{
			return len = n.length();
			}
		// Hashing algorithim 
		int hash()
			{
			int num;
			for(int i= 0; i < len; i++)
				rem = (rem*10 + n[i] - '0') % m;
			return rem;
			}
	};

int main()
	{
	Horner get;
	get.values();
	get.length();
	cout << "The remainder is: " << get.hash();
	}
