#include <iostream>
#include <string>
using namespace std;

int main()
{
	//next 10 lines of code collect the name of the Importer, product, and the product value
	cout << "Importer: ";
	string Importer;
	getline(cin, Importer);

	//next three if statements give errors and prompt the user if they enter invalid inputs for Importer, product value, and product
	if (Importer == "")
	{
		cout << "You must enter an importer." << endl;
		cout << "Importer: ";
		getline(cin, Importer);
	}

	cout << "Product value (in trillions): ";
	double productValue;
	cin >> productValue;

	if (productValue < 0)
	{
		cout << "The product value must not be negative." << endl;
		cout << "Product value (in trillions): ";
		cin >> productValue;
	}

	cin.ignore(10000, '\n');		//must use so getline works in line 18
	cout << "Product: ";
	string product;
	getline(cin, product);


	if (product == "")
	{
		cout << "You must enter a product." << endl;
		//cin.ignore(10000, '\n');		//must use so getline works in line 18 (already used above)
		cout << "Product: ";
		getline(cin, product);
	}

	cout << "---" << endl;

	//chunk of code below calculates all possible duties
	double duty;
	double duty1 = 0.31 * productValue;
	double duty2 = 0.31 * 500 + 0.25 * (productValue - 500);
	double duty3 = 0.31 * 500 + 0.29 * (productValue - 500);
	double duty4 = (0.31 * 500) + (0.29 * 400) + (0.22 * (productValue - 900));
	double duty5 = (0.31 * 500) + (0.25 * 400) + (0.22 * (productValue - 900));


	string pigs;
	string mud;

	//if else code below determines which duty is correct based on the product value
	if (productValue <= 500)
		duty = duty1;
	else if (productValue <= 900 && (product == pigs || product == mud))
		duty = duty3;
	else if (productValue <= 900 && product != pigs && product != mud)
		duty = duty2;

	else if (productValue > 900 && (product == "mud" || product == "pigs")) //This line not working
		duty = duty4;

	else if (productValue > 900 && product != "pigs" && product != "mud")
		duty = duty5;



	/*
	if (!isalnum(Importer[0]))							//ty jgoh.  replace isaplha w/ isalnum (alphabet and numbers)
	{													//the if statement covers the case where use inputs spaces or tab or numebrs
	cout << "You must enter an importer." << endl;
	return 1;
	}
	*/

	cout.setf(ios::fixed);	//cout returns decimals with fixed
	cout.precision(2);		//to the hundreds place

	cout << "The import duty for " << Importer << " is G" << duty << " trillion." << endl;
	return 1;
}


