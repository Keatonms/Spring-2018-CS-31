/*
Keaton Smith
CS 31
Project 3
5/7/2018

to fix:
length of a sustained note cannot be 0 or 1

*/


#include <iostream>
#include <string>
using namespace std;

bool hasCorrectSyntax(string song);	//(doesn't imply translatable!!!)
bool isTranslatable(string song);
bool isCorrectChar(char c);
int translateSong(string song, string& instructions, int& badBeat);
int stringToInt(string NumberAsString);
int isTranslatableReturn(int x);	//for badbeat returns


int main()
{

	string myinstructions="";
	int mybadbeat=0;

	string song;
	cout << "song: ";
	getline(cin, song);

	//int myx;

	if (hasCorrectSyntax(song))
	{
		cout << "The song has correct syntax" << endl;
	}
	else
	{
		cout << "ERROR: Incorrect Syntax" << endl;
	}

	if (isTranslatable(song))
		cout << "is translatable" << endl;
	else
		cout << "not translatable" << endl;

	//isTranslatableReturn(myx);

	translateSong(song, myinstructions, mybadbeat);
}

bool hasCorrectSyntax(string song)
{
	{
		for (int k = 0; k <= song.size() - 1; k++)	//TEST 1: checks that all characters are valid
		{
			if (!isCorrectChar(song[k]))
			{
				//cout << "Test 1" << endl;
				return false;
			}
		}

		while (song.size() != 0)
		{

			//song.substr(0, song.size()-1);

			if (song.size() <= 2 && isalpha(song[0]) && isalpha(song[1]))	//TEST 2: case where letter is not terminated g/
			{
				//cout << "TEST 2" << endl;
				return false;
			}

			else if (song.size() >= 3 && isalpha(song[0]) && isdigit(song[1]) && song[2] != '/' && isalpha(song[2]))	// TEST 3: e.g. g9- or g9g
			{
				//cout << "TEST 3" << endl;
				return false;
			}

			else if (song[0] == '/')
			{
				song = song.substr(1, song.size() - 1);
				continue;
			}

			else if (song.size() >= 2 && isalpha(song[0]) && song[1] == '/')
			{
				song = song.substr(2, song.size() - 2);
				continue;
			}

			else if (song.size() > 3 && isalpha(song[0]) && isdigit(song[1]) && isdigit(song[2]))	//double digit case
			{
				if (song[3] == '/')
				{
					song = song.substr(3, song.size() - 3);
					continue;
				}
				else
					return false;
			}

			else if (song.size() >= 2 && isalpha(song[0]) && isdigit(song[1]))	//TEST 5: case ex: g3///
			{
				if (song[2] == '/')
				{
					song = song.substr(2, song.size() - 2);
					continue;
				}
				else
					return false;
			}

			else return true;
		}
		return true;
	}
}

bool isTranslatable(string song)
{
	for (int k = 0; k <= song.size() - 1; k++)	//TEST 1: checks that all characters are valid
	{
		if (!isCorrectChar(song[k]))
		{
			//cout << "Test 1" << endl;
			return false;
		}
	}

	while (song.size() != 0)
	{

		//song.substr(0, song.size()-1);

		if (song.size() <= 2 && isalpha(song[0]) && isalpha(song[1]))	//TEST 2: case where letter is not terminated
		{
			//cout << "TEST 2" << endl;
			return false;
		}

		else if (song.size() >= 3 && isalpha(song[0]) && isdigit(song[1]) && song[2] != '/' && isalpha(song[2]))	// TEST 3: e.g. g9- or g9g
		{
			//cout << "TEST 3" << endl;
			return false;
		}

		else if (song[0] == '/')
		{
			song = song.substr(1, song.size() - 1);
			continue;
		}

		else if (song.size() >= 2 && isalpha(song[0]) && song[1] == '/')	//(no sustained note)
		{
			song = song.substr(2, song.size() - 2);
			continue;
		}

		else if (song.size() > 3 && isalpha(song[0]) && isdigit(song[1]) && isdigit(song[2]))	//TEST 4: case: g03///
		{
			int numSlashes = 0;
			for (int n = 3; n <= song.size() - 1 && n < 102; n++)	//finds the number of slashes following g03
			{
				if (song[n] == '/')
					numSlashes++;
				else
					break;
			}

			int numIndicated = stringToInt(song.substr(1, 2));
			//cout << numIndicated;

			if (numSlashes >= numIndicated)
			{
				song = song.substr((numSlashes + 1), song.size() - (numSlashes + 1));	// +1?
				continue;
			}
			else
			{
				//cout << "TEST 4" << endl;
				isTranslatableReturn(3);
				//badBeat = song.size() - 1;
				return false;
			}
		}

		else if (song.size() >= 2 && isalpha(song[0]) && isdigit(song[1]))	//TEST 5: case ex: g3///
		{
			int numSlashes2 = 0;
			for (int n = 2; n < 11 && n <= song.size() - 1; n++)	//finds the number of preceding slashes up to 9
			{
				if (song[n] == '/')
					numSlashes2++;
				else
					break;
			}

			int s = stringToInt(song.substr(1, 1));	//ex: g3/// converts the 3 to an int for the following if statement

			if (numSlashes2 >= s)
			{
				song = song.substr(s + 2, song.size() - (s + 2));
				continue;
			}
			else
			{
				//cout << "TEST 5" << endl;
				isTranslatableReturn(3);
				return false;
			}
		}
	}
	return true;
}

bool isCorrectChar(char c)
{
	if (c == '/' || c == 'r' || c == 'g' || c == 'y' || c == 'b' || c == 'o' || c == 'R' || c == 'G' || c == 'Y' || c == 'B' || c == 'O' || isdigit(c))
		return true;
	else
		return false;
}

int translateSong(string song, string& instructions, int& badBeat)
{

	if (isTranslatable(song))
	{
		while (song.size() != 0)
		{
			if (song[0] == '/')	//(no sustained note): no color
			{
				instructions += 'x';
				song = song.substr(1, song.size() - 1);
			}
			else if (song.size() >= 2 && isalpha(song[0]) && song[1] == '/')	//(no sustained note): yes color
			{
				instructions += song[0];
				song = song.substr(2, song.size() - 2);
			}

			else if (song.size() > 3 && isalpha(song[0]) && isdigit(song[1]) && isdigit(song[2]))	//(sustained note): double digit
			{
				int numSlashes = 0;
				int m = 0;
				for (int n = 3; n <= song.size() - 1 && n < 102; n++)	// g03/// becomes GGG
				{
					int j = stringToInt(song.substr(1, 2));
					if (song[n] == '/')
					{
						numSlashes++;
						if (numSlashes <= j)
						{
							instructions += toupper(song[0]);
							m++;
						}
						else
							continue;
					}
				}
				song = song.substr(3 + m, (song.size() - (3 + m)));
				continue;
			}


			else if (song.size() >= 2 && isalpha(song[0]) && isdigit(song[1]))	//(sustained note): single digit
			{
				int numSlashes2 = 0;
				int m = 0;			//number of slashes up to number indicated
				for (int n = 2; n < 11 && n <= song.size() - 1; n++)	//finds the number of preceding slashes up to 9
				{
					int j = stringToInt(song.substr(1, 1));
					if (song[n] == '/')
					{
						numSlashes2++;
						if (numSlashes2 <= j)
						{
							instructions += toupper(song[0]);	// g3/// becomes GGG
							m++;
						}
					}
					else
					{
						if (m < 2)
						{
						badBeat = m;	// doesn't work according to spec if while loop isn't on first iteration
						return 2;
						}
						continue;
					}
						

				}
				song = song.substr(2 + m, song.size() - (2 + m));
				continue;
			}


		}
		//cout << "reached instructions" << endl;
		cout << instructions << endl;
		return 0;
	}

	else
	{
		return 1;
	}

}

int stringToInt(string NumberAsString)	//depends on ASCII
{
	int NumberAsInteger = 0;
	for (int i = 0; i < NumberAsString.size(); i++)
		NumberAsInteger = NumberAsInteger * 10 + (NumberAsString[i] - '0');

	return NumberAsInteger;
}

int isTranslatableReturn(int x)
{
	return x;
}
