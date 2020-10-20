#include "dictionary.h"
#include <iterator>

dictionary::dictionary()
{
	//default constructor, not sure what it's needed for
}

int dictionary::searchForward(list<DictEntry> &wordList, wordType &findString)
{
	list <DictEntry>::iterator it;
	int count = 0;

	for (it = wordList.begin(); it != wordList.end(); it++)
	{
		count++;
		if (it->getWord() == findString)
		{
			return count;
		}
	}

	return 0;
}

int dictionary::searchBackward(list<DictEntry> &wordList, wordType &findString)
{
	list <DictEntry>::reverse_iterator it;
	int count = 0;

	for (it = wordList.rbegin(); it != wordList.rend(); it++)
	{
		count++;
		if (it->getWord() == findString)
		{
			return count;
		}
	}

	return 0;
}

void dictionary::revPrintList(ostream& output, list<DictEntry> &wordList)
{
	list <DictEntry>::reverse_iterator it;
	
	for (it = wordList.rbegin(); it != wordList.rend(); it++)
	{
		output << it->getWord() << endl;
	}
}