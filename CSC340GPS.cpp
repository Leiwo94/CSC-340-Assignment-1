// CSC340GPS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int maxLocations = 10;
long long LatLocations[10];
long long LonLocations[10];
int numLocations = 0;

void getXYLocations();
void NewXYLocation(long long*, long long*);
void removeXY();


int main()
{
	int option = 0;

	cout << "Please choose from the following options:" << endl;
	cout << "1) Store a new location." << endl;
	cout << "2) Remove a location." << endl;
	cout << "3) Show all stored locations." << endl;
	cout << "4) End Program." << endl;

	cin >> option;

	do
	{

		if (option == 1)
		{
			// use new location function

			NewXYLocation(LatLocations, LonLocations);

			main();
		}
		else if (option == 2)
		{
			removeXY();
			main();
		}
		else if (option == 3)
		{
		 getXYLocations();

		 main();
		}
		else if (option == 4) {
			exit(0);
		}


	} while (option > 0);

	return 0;
}

void NewXYLocation(long long* LatLocations, long long* LonLocations)
{

	if (numLocations >= maxLocations)
	{
		cout << "Unable to add anymore locations. Please remove a location before trying to add one again." << endl;
		return;
	}

	long long lat, lon;

	cout << "Enter a Latitude and Longitude to store." << endl;

	cin >> lat;
	cin >> lon;

	LatLocations[numLocations] = lat;
	LonLocations[numLocations] = lon;
	numLocations++;

	cout << "Your Location: Latitude " << lat << " and Longitude " << lon << " has been stored. You have " << numLocations << " locations stored." << endl << endl;
}

void getXYLocations() {
	if (numLocations == 0) {
		cout << "You don't have any Locations saved yet. Go enter some first." << endl;
		main();
	}
	
		cout << "Here are your stored locations:" << endl;
		for (int i = 0; i < numLocations; i++) {
			cout << i+1 << ": Latitude: " << LatLocations[i] << " and Longitude :" << LonLocations[i] << endl;
		}
		cout << endl;
	
}

void removeXY() {
	if (numLocations == 0) {
		cout << "You don't have any Locations saved yet. Go enter some first." << endl;
		main();
	}

	cout << "Here are your stored locations:" << endl;
	for (int i = 0; i < numLocations; i++) {
		cout << i + 1 << ": Latitude: " << LatLocations[i] << " and Longitude :" << LonLocations[i] << endl;
	}
	cout << endl;

	int userSelection;
	cout << "Please select a location to remove." << endl;
	cin >> userSelection;

	if (userSelection < 1 || userSelection > numLocations) {
		cout << "Please select a valid location." << endl;
		return;
	}

	int deletedLocation = userSelection - 1;
	cout << "You have chosen to remove Latitude " << LatLocations[deletedLocation] << " and longitude " << LonLocations[deletedLocation] << "." << endl;

	for (int i = deletedLocation; i < numLocations - 1; i++) {
		LatLocations[i] = LatLocations[i + 1];
		LonLocations[i] = LonLocations[i + 1];
	}

	numLocations--;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
