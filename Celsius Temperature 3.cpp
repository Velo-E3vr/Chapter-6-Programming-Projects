#include <iostream>
#include <iomanip>
using namespace std;

// Prototype
double celsius(double fahrenheit);

// Converts Fahrenheit to Celsius and prints a table
int main() {
    cout << fixed << setprecision(2);
    cout << "Fahrenheit   Celsius\n";
    cout << "---------------------\n";

    // You can adjust the range if your instructions say differently
    for (int f = 0; f <= 20; ++f) {
        double c = celsius(f);
        cout << setw(6) << f << setw(12) << c << endl;
    }

    return 0;
}

// Uses the formula C = (5/9) * (F - 32)
double celsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}
