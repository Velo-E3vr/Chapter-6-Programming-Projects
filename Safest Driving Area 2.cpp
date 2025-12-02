#include <iostream>
#include <string>
using namespace std;

// Prototypes
int getAccidents(const string& regionName);
void findLowest(int north, int south, int east, int west, int central);

int main() {
    int north, south, east, west, central;

    // Get input for each region
    north = getAccidents("North");
    south = getAccidents("South");
    east = getAccidents("East");
    west = getAccidents("West");
    central = getAccidents("Central");

    // Determine which region is safest
    findLowest(north, south, east, west, central);

    return 0;
}

// Prompts user for accidents for one region, validates non-negative
int getAccidents(const string& regionName) {
    int accidents;
    do {
        cout << "Enter the number of accidents in the " << regionName << " region: ";
        cin >> accidents;

        if (accidents < 0) {
            cout << "Error: accidents cannot be negative.\n";
        }
    } while (accidents < 0);

    return accidents;
}

// Finds and displays region with smallest accidents
void findLowest(int north, int south, int east, int west, int central) {
    string safestRegion = "North";
    int minAccidents = north;

    if (south < minAccidents) {
        minAccidents = south;
        safestRegion = "South";
    }
    if (east < minAccidents) {
        minAccidents = east;
        safestRegion = "East";
    }
    if (west < minAccidents) {
        minAccidents = west;
        safestRegion = "West";
    }
    if (central < minAccidents) {
        minAccidents = central;
        safestRegion = "Central";
    }

    cout << "\nThe safest driving area is the " << safestRegion
        << " region with " << minAccidents << " accidents.\n";
}
