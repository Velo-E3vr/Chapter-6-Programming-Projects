#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double getLength();
double getWidth();
double getArea(double length, double width);
double getPerimeter(double length, double width);
void displayData(double length, double width, double area, double perimeter);

int main() {
    double length = 0.0;
    double width = 0.0;
    double area = 0.0;
    double perimeter = 0.0;

    // Get validated dimensions
    length = getLength();
    width = getWidth();

    // Calculate area and perimeter using separate functions
    area = getArea(length, width);
    perimeter = getPerimeter(length, width);

    // Display all results
    displayData(length, width, area, perimeter);

    return 0;
}

// Gets a valid length from the user (> 0)
double getLength() {
    double length;
    do {
        cout << "Enter the rectangle length (greater than 0): ";
        cin >> length;

        if (length <= 0) {
            cout << "Error: length must be greater than 0." << endl;
        }
    } while (length <= 0);

    return length;
}

// Gets a valid width from the user (> 0)
double getWidth() {
    double width;
    do {
        cout << "Enter the rectangle width (greater than 0): ";
        cin >> width;

        if (width <= 0) {
            cout << "Error: width must be greater than 0." << endl;
        }
    } while (width <= 0);

    return width;
}

// Calculates area = length * width
double getArea(double length, double width) {
    return length * width;
}

// Calculates perimeter = 2 * (length + width)
double getPerimeter(double length, double width) {
    return 2.0 * (length + width);
}

// Displays all four values neatly
void displayData(double length, double width, double area, double perimeter) {
    cout << fixed << setprecision(2);
    cout << "\nRectangle Properties\n";
    cout << "---------------------\n";
    cout << "Length:    " << length << endl;
    cout << "Width:     " << width << endl;
    cout << "Area:      " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
}
