/*
Test: (11)
tally				+
findmatch			+
findRun
potitionOfMin		+
moveToEnd			+
moveToBeginning
findDifference
eliminateDups
subsequence
makeMerger
seperate


Not working: (0)

Maybe working: (11)
seperate
subsequence
moveToBeginning
makeMerger
eliminateDups
moveToEnd
tally
findMatch
findRun
positionOfMin
findDifference
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int tally(const string a[], int n, string target);
int findMatch(const string a[], int n, string target);
bool findRun(const string a[], int n, string target, int& begin, int& end);
int positionOfMin(const string a[], int n);
int moveToEnd(string a[], int n, int pos);
int moveToBeginning(string a[], int n, int pos);
int findDifference(const string a1[], int n1, const string a2[], int n2);
int eliminateDups(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max);
int separate(string a[], int n, string separator);


int main()
{
	string h[7] = { "romanoff", "thor", "rogers", "banner", "", "parker", "rogers" };
	assert(tally(h, 7, "rogers") == 2);
	assert(tally(h, 7, "") == 1);
	assert(tally(h, 7, "rhodes") == 0);
	assert(tally(h, 0, "rogers") == 0);
	assert(findMatch(h, 7, "rogers") == 2);
	assert(findMatch(h, 2, "rogers") == -1);
	int bg;
	int en;
	assert(findRun(h, 7, "banner", bg, en) && bg == 3 && en == 3);

	string g[4] = { "romanoff", "thor", "banner", "parker" };
	assert(positionOfMin(g, 4) == 2);
	assert(findDifference(h, 4, g, 4) == 2);

	assert(subsequence(h, 7, g, 4));
	assert(moveToEnd(g, 4, 1) == 1 && g[1] == "banner" && g[3] == "thor");
	///*
	string f[4] = { "parker", "banner", "thor", "rogers" };
	assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "thor" && f[2] == "banner");
	//*/
	string e[5] = { "parker", "parker", "parker", "thor", "thor" };
	assert(eliminateDups(e, 5) == 2 && e[1] == "thor");
	///*
	string x[4] = { "rhodes", "rhodes", "tchalla", "thor" };
	string y[4] = { "banner", "parker", "rhodes", "rogers" };
	string z[10];
	assert(makeMerger(x, 4, y, 4, z, 10) == 8 && z[5] == "rogers");

	string a[5] = { "banner", "rhodes", "rogers", "stark", "tchalla" };
	string b[4] = { "parker", "rogers", "rogers", "thor" };
	string c[20];
	assert(makeMerger(a, 5, b, 4, c, 20) == 9 && c[1] == "parker" && c[7] == "tchalla");
	//*/
	assert(separate(h, 7, "rogers") == 3);

	/*
	string d[9] = {
	"thor", "romanoff", "parker", "parker", "stark", "stark", "stark", "parker", "parker"
	};
	assert(tally(d, 9, "parker") == 4 && tally(d, 5, "stark") == 1 && tally(d, 9, "tchalla") == 0);

	string people[5] = { "parker", "thor", "stark", "banner", "romanoff" };
	assert(findMatch(people, 5, "banner") == 3);

	string d[9] = {
	"thor", "romanoff", "parker", "parker", "stark", "stark", "stark", "parker", "parker"
	};
	int b;
	int e;
	bool b1 = findRun(d, 9, "parker", b, e);
	//assert(b1 == true && b == 2 && e == 3);

	assert(positionOfMin(people, 5) == 3);

	string people[5] = { "parker", "thor", "stark", "banner", "romanoff" };
	assert(moveToEnd(people, 5, 1) == 1 && people[2] == "banner");

	string people[5] = { "parker", "thor", "stark", "banner", "romanoff" };
	int j = moveToBeginning(people, 5, 2);
	assert(j == 2 && people[1] == "parker");

	string cast[5] = { "parker", "thor", "stark", "banner", "romanoff" };
	string roles[4] = { "parker", "thor", "tchalla", "rhodes" };
	int k = findDifference(cast, 5, roles, 4);  //  returns 2
	int m = findDifference(cast, 2, roles, 1);  //  returns 1
	assert(k == 2 && m == 1);

	string d[9] = {
	"thor", "romanoff", "parker", "parker", "stark", "stark", "stark", "parker", "parker"
	};
	int p = eliminateDups(d, 9);  //  returns 5
	//  d[0] through d[4] now contain  "thor" "romanoff" "parker" "stark" "parker"
	//  We no longer care what strings are in d[5] and beyond.
	assert(p == 5 && d[1] == "romanoff");

	string big[10] = { "parker", "thor", "stark", "banner", "romanoff", "stark" };
	string little1[10] = { "thor", "banner", "romanoff" };
	bool b1 = subsequence(big, 6, little1, 3);  // returns true
	string little2[10] = { "stark", "thor" };
	bool b2 = subsequence(big, 6, little2, 2);  // returns false
	string little3[10] = { "thor", "stark", "stark" };
	bool b3 = subsequence(big, 6, little3, 3);  // returns true
	string little4[10] = { "thor", "thor", "stark" };
	bool b4 = subsequence(big, 6, little4, 3);  // returns false
	assert(b1 == true && b2 == false && b3 == true && b4 == false);

	string x[5] = { "banner", "rhodes", "rogers", "stark", "tchalla" };
	string y[4] = { "parker", "rogers", "rogers", "thor" };
	string z[20];
	int n = makeMerger(x, 5, y, 4, z, 20);  // returns 9
	// z has  banner parker rhodes rogers rogers rogers stark tchalla thor
	assert(n == 9 && z[2] == "rhodes");

	string f[6] = { "rhodes", "banner", "stark", "parker", "thor", "rogers" };
	int r = separate(f, 6, "romanoff");  //  returns 4
	// f might now be
	//	"rhodes"  "banner"  "rogers"  "parker"  "thor"  "stark"
	// or   "rogers"  "parker"  "banner"  "rhodes"  "stark"  "thor"
	// or several other orderings.
	// The first 4 elements are < "romanoff"; the last 2 aren't.
	string g[4] = { "romanoff", "rogers", "thor", "banner" };
	int s = separate(g, 4, "rogers");  //  returns 1
	// g must now be either
	//	"banner"  "rogers"  "romanoff"  "thor"
	// or	"banner"  "rogers"  "thor"  "romanoff"
	// All elements < "rogers" (i.e., "banner") come before all others.
	// All elements > "rogers" (i.e., "thor" and "romanoff") come
	//      after all others.
	assert(r == 4 && s == 1);
	*/

	cout << "All tests succeeded" << endl;
}


int tally(const string a[], int n, string target)
{
	int tally = 0;
	if (n < 0)
	{
		return -1;
	}

	for (int k = 0; k < n; k++)
	{
		if (a[k] == target)
			tally++;
		else
			continue;
	}
	return tally;
}

int findMatch(const string a[], int n, string target)
{
	for (int k = 0; k < n; k++)
	{
		if (a[k] == target)
			return k;
		else
			continue;
	}
	return -1;
}

bool findRun(const string a[], int n, string target, int& begin, int& end)
{
	if (n < 0)
		return false;
	for (int k = 0; k < n; k++)
	{
		if (a[k] == target)
		{
			begin = k;
			end = k;
			for (int m = 1; m < (n - k); m++)	//double check operator in this line for fencepost error
			{
				if (a[k + m] == target)
					end++;
				else
					return true;
			}
		}
		else
			continue;
	}
	return false;
}

int positionOfMin(const string a[], int n)
{
	if (n <= 0)
		return -1;

	string lowest = a[0];
	for (int k = 0; k < n; k++)
	{
		if (a[k] <= lowest)
			lowest = a[k];
	}
	for (int j = 0; j < n; j++)
	{
		if (a[j] == lowest)
		{
			return j;
		}
		else
			continue;

	}

	return 0; //only if n is less than the size of the array
}

int moveToEnd(string a[], int n, int pos)
{
	string end = a[pos];
	for (int k = pos; k < (n - 1); k++)
	{
		a[k] = a[k + 1];
	}
	a[n - 1] = end;
	return 1;
}

int moveToBeginning(string a[], int n, int pos)
{
	string first = a[pos];
	for (int k = (pos); k >= 1; k -= 1)
	{
		a[k] = a[k - 1];
	}
	a[0] = first;
	return pos;
}

int findDifference(const string a1[], int n1, const string a2[], int n2)
{
	for (int k = 0; k < n1 && k < n2; k++)
	{
		if (a1[k] == a2[k])
			continue;
		else
			return k;
	}
	if (n1 > n2)
		return n2;
	if (n2 > n1)
		return n1;

	return 0;	//case where the arrays are the same
}

int eliminateDups(string a[], int n)
{

	int i = 1;
	int c = 0;
	for (int k = 0; k < (n - 1); k++)
	{
		if (a[k + 1] == a[k])
		{
			for (int j = 1; j < (n - k - 1); j++)
			{
				a[k + j] = a[k + j + 1];
				n--;
				//cout << "copy" << endl;	//for debugging
			}
			k--;
		}
		else
		{
			i++;
			continue;
		}
	}
	return i;
}

bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0 || n2 > n1)
		return false;
	else if (n2 == 0)
		return false;

	int i = 0;
	for (int k = 0; k < n1 && i < n2; k++)
	{
		if (a1[k] == a2[i])		//if equal check the next string in a2 against the rest of a1
		{
			i++;
			continue;
		}
		else
			continue;
	}
	if (i == n2)
	{
		return true;
	}
	else
		return false;
}

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
	int i = 0;

	if ((n1 + n2) > max)
		return -1;

	for (int k = 0; k < (n1 - 1); k++)	// checks a1 is in nondecreasing order
	{
		if (a1[k] <= a1[k + 1])
			continue;
		else
			return -1;
	}

	for (int k = 0; k < (n2 - 1); k++)	// checks a2 is in nondecreasing order
	{
		if (a2[k] <= a2[k + 1])
			continue;
		else
			return -1;
	}

	int m = 0;
	for (int k = 0; k < n1 && i < n2; k++)
	{
		if (a1[k] <= a2[i])
		{
			result[k + m] = a1[k];
			continue;
		}
		else
		{
			result[k + m] = a2[i];
			i++;
			k--;
			m++;
			continue;
		}
	}
	return (n1 + n2);
}

int separate(string a[], int n, string separator)
{
	///*
	if (n < 0)
		return -1;
	else if (n == 0)
		return 0;

	int p = 0;
	for (int m = 0; m < n; m++)		//checks case where no strings in array are greater than separator
	{
		if (a[m] < separator)
		{
			continue;
		}
		else
			p++;
	}
	if (p == 0)
		return n;

	for (int k = 0; k < n; k++)
	{
		if (a[k] >= separator)
		{
			for (int j = 1; j < (n - k); j++)
			{
				if (a[k + j] >= separator)
					continue;
				else
				{
					string temp = a[k + j];
					a[k + j] = a[k];
					a[k] = temp;
					break;
				}
			}
		}
	}
	int R;
	for (int l = 0; l < n; l++)	//finds the position of the first element that is not less than separator to return R
	{
		if (a[l] >= separator)
		{
			R = l;
			l = n;	// will 'break' work the exact same?
		}
	}
	return R;
}
