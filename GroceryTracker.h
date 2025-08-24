/*GroceryTracker.h
* Author: Kristen Gant
* Date: 8/17/25
* Project 3 Component
* Purpose: Header file declares the GroceryTracker class
*/

#pragma once

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

using namespace std;

// establish GroceryTracker class
class GroceryTracker {
private:
	// map stores item name and frequency
	map<string, int> itemFrequencies;
	// input data file name
	string inputFileName;
	// output data file name
	string outputFileName;

	// helper functions
	void loadItems(); // read and count items
	void writeFrequenciesToFile(); // back up data to frequency.dat
	string toLower(const string& str); // prevent user input from being case sensitive
	
public:
	// constructor
	GroceryTracker(); // load data and write backup
	void printFrequencyOfItem(const string& item); // print item frequency
	void printAllFrequencies(); // print all item frequencies
	void printHistogram(); // print histogram of all items
};

#endif // !GROCERYTRACKER_H