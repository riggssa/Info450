// MakeChange.cpp
//

#include "stdafx.h"
#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	double Cost;
	double Payment;
	double More;
	double Change;
	int Dollars;
	int Quarters;
	int Dimes;
	int Nickels;
	while (true)
	{
		cout << "Please select your item and enter its cost now, or press 0 to cancel transaction." << endl;
		cin >> Cost;
// This is to end the loop by entering 0.
		if (Cost == 0)
			break;

		cout << "Enter payment now. This machine only accepts dollars, quarters, dimes and nickels." << endl;
		cin >> Payment;
//Overarching while loop, first thing to check is that cost is met
		while (Payment < Cost)
		{
			cout << "Payment does not match cost. Please pay more. You need $" << Cost - Payment << endl;
			cin >> More;
			Payment = Payment + More;
		}
//Keep customer informed
		std::cout << std::fixed << std::setprecision(2) << "You paid $" << Payment << endl;
//Only give change if payment is not exact
		if (Payment == Cost)
			cout << "You can count! No change." << endl;
//make change, starting with largest currency tendered
		else if (Payment > Cost)
		{
			Change = Payment - Cost;
			std::cout << std::fixed << std::setprecision(2) << "Your change is $" << Change << endl;
			Dollars = Change / 1.00;
			int Change2 = (Change - Dollars) * 100;
			Quarters = Change2 / 25;
			Dimes = (Change2 %= 25) / 10;
			Nickels = (Change2 %= 10) / 5;

			cout << Dollars << "Dollars," << Quarters << " Quarters," << Dimes << " Dimes, and" << Nickels << " Nickels." << endl;

		}

	}

	return 0;
}
