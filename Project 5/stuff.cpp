#include <iostream>
#include <fstream>
#include <cctype>	// isspace()
#include <cstring>
using namespace std;

int stuff(int lineLength, istream& inf, ostream& outf);

int main()
{
	ifstream infile("C:/Users/keato/Desktop/textinput6.txt");    // infile is a name of our choosing
	ofstream outfile("C:/Users/keato/Desktop/textoutput.txt");
	if (!infile)		        // Did opening the file fail?
	{
		cerr << "Error: Cannot open textinput.txt!" << endl;
		return 5;
	}



	int length = 10;
	int j = stuff(length, infile, outfile);
	cerr << j << endl;
}

int stuff(int lineLength, istream& inf, ostream& outf)
{
	if (lineLength < 1)
		return 2;

	const int MAX = lineLength;

	char buf[1024];
	int count = 0;

	// read in an entire line (max length = 1024)
	while (inf.getline(buf, 1024))
	{
		int j = 0;
		char word[140];

		// loop through each character of the buffer
		for (int i = 0; i <= strlen(buf); i++)
		{

			// check for hyphens
			if (buf[i] == '-' && buf[i - 1] != ' ' && (count + i + 1) > MAX)
			{

				//outf << "i is equal to: " << i << endl;
				for (int k = 0; buf[k + count] != '-' && word[k] != '-'; k++)
				{
					outf << word[k];
				}

				outf << buf[i] << endl;
				count = 0;
				j = 0;
				i++;
			}

			// keep growing our word until we hit a space or the end of the buffer
			if (buf[i] != ' ' && i != strlen(buf))
			{
				word[j++] = buf[i];
			}

			else
			{
				// skip empty words
				if (j == 0)
					continue;

				// terminate our word
				word[j] = '\0';
				j = 0;

				// check for new paragraph
				if (!strcmp(word, "#P#"))
				{
					outf << endl << endl;
					count = 0;
				}
				else
				{
					// create a newline if neccessary
					if ((count + strlen(word) + 1) > MAX)
					{
						outf << endl;
						count = 0;
					}

					count += strlen(word) + 1;
					outf << word << " ";

					// add an extra space after periods
					if (word[strlen(word) - 1] == '.')
						outf << " ";


					// return 1 if strlen(word) exceeds MAX

					if (strlen(word) > MAX)
					{
						return 1;	//SHOULD BE 1
					}


				}
			}
		}
	}

	outf << endl;
	return 0;
}

