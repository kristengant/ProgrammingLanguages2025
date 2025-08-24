/*main.cpp
* Author: Kristen Gant
* Date: 8/17/25
* Project 3 Component
* Purpose: Run Grocery Tracker program for Corner Grocery
* application. Provide menu for user to interact with.
*/

#include <iostream>
#include <string>
#include "GroceryTracker.h"

using namespace std;

int main() {
	// create GroceryTracker instance to load data
	GroceryTracker tracker;
	int choice;
	string item;

	// display menu loop and user input
	do {
		cout << endl << "***** Corner Grocer Menu *****" << endl;
		cout << "1. Search for an item" << endl;
		cout << "2. Print item list and frequencies" << endl;
		cout << "3. Print item histogram" << endl;
		cout << "4. Exit program" << endl;
		cout << "Enter your choice as a number 1-4: " << endl;
		cin >> choice;

		// input failure handling
		if (cin.fail()) {
			// clear fail state
			cin.clear();
			// discard invalid input
			cin.ignore(1000, '\n');
			choice = -1; // default case for failure handling
		}
		// validate user input
		switch (choice) {
		case 1:
			cout << "Enter item to search for: ";
			cin.ignore(); // flush previous input
			getline(cin, item); // read full item name
			tracker.printFrequencyOfItem(item);
			break;
		case 2:
			tracker.printAllFrequencies();
			break;
		case 3:
			tracker.printHistogram();
			break;
		case 4:
			cout << "Exiting program..." << endl;
			break;
		// invalid input
		default:
			cout << "Invalid selection. Please enter 1, 2, 3, or 4." << endl;
		}
	// continue until user selects exit option
	} while (choice != 4);
	return 0;
}