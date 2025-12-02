#include <iostream>
#include <iomanip>
#include <cmath> // for ceil
using namespace std;

// Constants - adjust to match your Canvas instructions
const double COVERAGE_PER_GALLON = 112.0; // sq. feet per gallon
const double HOURS_PER_GALLON = 8.0;      // hours of labor per gallon
const double LABOR_RATE = 25.00;          // dollars per hour

// Prototypes
double getWallSpace();
double getPaintPrice();
double calculateGallons(double squareFeet);
double calculateHours(double squareFeet);
double calculatePaintCost(double gallons, double pricePerGallon);
double calculateLaborCharges(double hours);
void displayEstimate(double squareFeet, double gallons, double hours,
    double paintCost, double laborCost, double totalCost);

int main() {
    double wallSpace = getWallSpace();
    double pricePerGallon = getPaintPrice();

    // Calculate required values
    double gallonsNeeded = calculateGallons(wallSpace);
    double hoursNeeded = calculateHours(wallSpace);
    double paintCost = calculatePaintCost(gallonsNeeded, pricePerGallon);
    double laborCost = calculateLaborCharges(hoursNeeded);
    double totalCost = paintCost + laborCost;

    // Show the estimate
    displayEstimate(wallSpace, gallonsNeeded, hoursNeeded,
        paintCost, laborCost, totalCost);

    return 0;
}

// Gets total square feet to be painted
double getWallSpace() {
    double squareFeet;
    do {
        cout << "Enter the total square feet of wall space to be painted: ";
        cin >> squareFeet;

        if (squareFeet <= 0) {
            cout << "Error: square feet must be positive.\n";
        }
    } while (squareFeet <= 0);

    return squareFeet;
}

// Gets price per gallon of paint
double getPaintPrice() {
    double price;
    do {
        cout << "Enter the price of the paint per gallon: ";
        cin >> price;

        if (price <= 0) {
            cout << "Error: price must be positive.\n";
        }
    } while (price <= 0);

    return price;
}

// Calculates gallons needed, rounding up
double calculateGallons(double squareFeet) {
    double gallons = squareFeet / COVERAGE_PER_GALLON;
    // Round up to ensure enough paint is purchased
    return ceil(gallons);
}

// Calculates hours of labor needed
double calculateHours(double squareFeet) {
    return (squareFeet / COVERAGE_PER_GALLON) * HOURS_PER_GALLON;
}

// Calculates total paint cost
double calculatePaintCost(double gallons, double pricePerGallon) {
    return gallons * pricePerGallon;
}

// Calculates labor charges
double calculateLaborCharges(double hours) {
    return hours * LABOR_RATE;
}

// Displays a neat cost breakdown
void displayEstimate(double squareFeet, double gallons, double hours,
    double paintCost, double laborCost, double totalCost) {
    cout << fixed << setprecision(2);
    cout << "\nPaint Job Estimate\n";
    cout << "------------------\n";
    cout << "Wall space:        " << squareFeet << " sq. ft.\n";
    cout << "Gallons needed:    " << gallons << endl;
    cout << "Hours of labor:    " << hours << endl;
    cout << "Paint cost:       $" << paintCost << endl;
    cout << "Labor cost:       $" << laborCost << endl;
    cout << "Total cost:       $" << totalCost << endl;
}
