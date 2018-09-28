#include <iostream>
#include <string>
using namespace std;

bool hasCorrectSyntax(string song);	//(doesn't imply translatable!!!)
bool isCorrectChar(char c);
int translateSong(string song, string& instructions, int& badBeat);


int main()
{
	const string song;
	getline(cin, song);

	if (hasCorrectSyntax(song))
	{
		cout << "The song has correct syntax";
	}
	else
	{
		cout << "ERROR: Incorrect Syntax";
	}

}

bool hasCorrectSyntax(string song)
{
	if (song.size() < 0)		//checks that song is a sequence of zero or more beats
		return false;

	for (int k = 0; k <= song.size(); k++)	//checks that all characters are valid
	{
		if (!isCorrectChar(song[k]))
			return false;
	}

	for (int k = 0; k <= song.size(); k++)
	{
		if (song[k] == '/')	
			continue;

		else if (isalpha[song[k] && isalpha(song[k+1]))	//case where letter is not terminated
			return false;

		else if (isalpha(song[k]) && song[k + 1] == '/')
		{
			k++;
			continue;
		}

		else if (isalpha(song[k]) && isdigit(song[k + 1]) && isdigit(song[k + 2]));	//check two digit before one digit!!!
		{
			int numSlashes = 0;						
				for (int n = 3; song[k + n] = '/'; n++)	//finds the number of slashes preceding a04
				{
					numSlashes++;
				}

				string stringSlashes = "numslashes";	//converts numSlashes from an int to a string of char for the following if statement
	
				if (song[k+1] != stringSlashes[0] || song[k+2] != stringSlashes[1])	//checks that the number of preceding slashes is the same as the number
					return false;
		}

		else if (isalpha(song[k] && isdigit(song[k + 1]))
		{
			int numSlashes2 = 0;
				for(int n = 2; song[k+n] = '/'; n++
				{
					numSlashes2++;
				}

			char c = 'numSlashes2'

			if(c != song[k+1])
				return false;
		}
	}
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
	if (hasCorrectSyntax(song))
	{

	}
	else
		return 1;
}