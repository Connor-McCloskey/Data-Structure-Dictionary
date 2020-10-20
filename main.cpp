/*
NAME: Connor McCloskey
LAST DATE MODIFIED: 03/05/2017
ASSIGNMENT: Data Structures Homework 6
DESCRIPTION: This program demonstrates double linked lists
and compares searching through them forward and backward.
STATUS: COMPLETE
COMMENTS: Program should run to specifications.
*/

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include "dictionary.h"
#include "DictEntry.h"
using namespace std;

int main()
{
	//Variables
	dictionary ListFunctions;
	ifstream inFile;
	ofstream outFile;
	list <DictEntry> wordList;
	list <DictEntry>::iterator it;
	int searchSteps = 0;
	wordType import;
	DictEntry importer;

	//Opening dictionary.txt and feeding its contents into the list
	inFile.open("dictionary.txt");

	while (!inFile.eof())
	{
		getline(inFile, import);
		importer.setWord(import);
		wordList.push_back(importer);
	}
	
	inFile.close();

	//Sorting the list
	wordList.sort();

	//Searching for terms
	inFile.open("findwords.txt");

	while (!inFile.eof())
	{
		getline(inFile, import);
		cout << "Searching for term: " << import << endl;
		searchSteps = ListFunctions.searchForward(wordList, import);
		if (searchSteps == 0)
		{
			cout << "Term not found." << endl;
		}
		else
		{
			cout << "Forward Search steps: " << searchSteps << endl;
			searchSteps = ListFunctions.searchBackward(wordList, import);
			cout << "Backward Search steps: " << searchSteps << endl;
		}
		cout << endl;
	}

	inFile.close();

	//Print to file
	cout << "Printing in reverse alphabetical order to file..." << endl;
	
	outFile.open("revsorted.txt");

	ListFunctions.revPrintList(outFile, wordList);

	outFile.close();
	
	cout << "Printing complete. Program closing. Have a nice day!" << endl;

	return 0;
}