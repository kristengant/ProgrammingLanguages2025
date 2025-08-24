/*GroceryTracker.cpp
* Author: Kristen Gant
* Date: 8/17/25
* Project 3 Component
* Purpose: Define the GroceryTracker class functions
* including loading item data, storing frequencies, and 
* displaying item frequencies and histograms.
*/

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <windows.h>

// helper function to change text color in histogram
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// constructor to initialize file names, load items, and write frequency data
GroceryTracker::GroceryTracker() {
	inputFileName = "CS210_Project_Three_Input_File.txt";
	outputFileName = "frequency.dat";
	loadItems();
	writeFrequenciesToFile();
}

// convert string to lowercase to prevent case sensitivity in user input
string GroceryTracker::toLower(const string& str) {
	string result = str;
	for (char& c : result) {
		c = tolower(static_cast<unsigned char>(c));
	}
	return result;
}

// read input file and update item frequencies map accordingly
void GroceryTracker::loadItems() {
	ifstream inFile(inputFileName);
	string item;

	// error handling if unable to open file
	if (!inFile) {
		cerr << "Error opening input file.";
		return;
	}

	// count each item
	while (inFile >> item) {
		++itemFrequencies[toLower(item)];
	}

	inFile.close();
}

// write item frequencies to output file
void GroceryTracker::writeFrequenciesToFile() {
	ofstream outFile(outputFileName);

	for (const auto& pair : itemFrequencies) {
		outFile << pair.first << " " << pair.second << "\n";
	}

	outFile.close();
}

// print how many times an item was purchased
void GroceryTracker::printFrequencyOfItem(const string& item) {
	auto it = itemFrequencies.find(toLower(item));
	if (it != itemFrequencies.end()) {
		cout << item << " was purchased " << it->second << " times." << endl;
	}
	else {
		cout << item << " was not purchased today." << endl;
	}
}

// print list of all items with purchase frequency
void GroceryTracker::printAllFrequencies() {
	cout << endl << "Item Purchase Frequencies:" << endl;
	for (const auto& pair : itemFrequencies) {
		cout << setw(12) << left << pair.first << " " << pair.second << endl;	
	}
}

// display histogram of item frequencies with color-coded asterisks
void GroceryTracker::printHistogram() {
	cout << "\nItem Purchase Histogram: " << endl;
	// color coded legend
	cout << "Inventory Legend: ";
	setColor(12); // red
	cout << "Low [1-3], ";
	setColor(14); // yellow
	cout << "Medium [4-6], ";
	setColor(10); // green
	cout << "High [6+]" << endl;
	setColor(7); // return to default color
	
	// histogram with color-coded asterisks
	for (const auto& pair : itemFrequencies) {
		cout << setw(12) << left << pair.first << " ";

		// color determination
		if (pair.second <= 3) {
			setColor(12); // Red = low inventory
		}
		else if (pair.second <= 6) {
			setColor(14); // Yellow = medium inventory
		}
		else {
			setColor(10); // Green = high inventory
		}

		// asterisk output for frequency
		for (int i = 0; i < pair.second; ++i) {
			cout << "*";
		}

		setColor(7); // reset color to default
		cout << endl;
	}
}