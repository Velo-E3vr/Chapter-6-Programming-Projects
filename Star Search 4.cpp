#include <iostream>
using namespace std;

// Prototypes
void getJudgeData(double& score);
double findLowest(double s1, double s2, double s3, double s4, double s5);
double findHighest(double s1, double s2, double s3, double s4, double s5);
double calcAverage(double s1, double s2, double s3, double s4, double s5);

int main() {
    double s1, s2, s3, s4, s5;
    double average;

    // Get and validate all five scores
    getJudgeData(s1);
    getJudgeData(s2);
    getJudgeData(s3);
    getJudgeData(s4);
    getJudgeData(s5);

    // Calculate the average after dropping high/low
    average = calcAverage(s1, s2, s3, s4, s5);

    cout << "\nFinal average score (after dropping highest and lowest): "
        << average << endl;

    return 0;
}

// Gets one judge's score by reference, with validation
void getJudgeData(double& score) {
    const double MIN_SCORE = 0.0;
    const double MAX_SCORE = 10.0; // or whatever your instructions say

    do {
        cout << "Enter judge's score (" << MIN_SCORE
            << " - " << MAX_SCORE << "): ";
        cin >> score;

        if (score < MIN_SCORE || score > MAX_SCORE) {
            cout << "Error: score out of range.\n";
        }
    } while (score < MIN_SCORE || score > MAX_SCORE);
}

// Returns the smallest of five scores
double findLowest(double s1, double s2, double s3, double s4, double s5) {
    double min = s1;
    if (s2 < min) min = s2;
    if (s3 < min) min = s3;
    if (s4 < min) min = s4;
    if (s5 < min) min = s5;
    return min;
}

// Returns the largest of five scores
double findHighest(double s1, double s2, double s3, double s4, double s5) {
    double max = s1;
    if (s2 > max) max = s2;
    if (s3 > max) max = s3;
    if (s4 > max) max = s4;
    if (s5 > max) max = s5;
    return max;
}

// Calculates the average after dropping the highest and lowest
double calcAverage(double s1, double s2, double s3, double s4, double s5) {
    double total = s1 + s2 + s3 + s4 + s5;
    double lowest = findLowest(s1, s2, s3, s4, s5);
    double highest = findHighest(s1, s2, s3, s4, s5);

    double adjustedTotal = total - lowest - highest;
    double average = adjustedTotal / 3.0;

    return average;
}
