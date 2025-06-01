#include<iostream>
using namespace std;

const int shifts = 3, days = 7;

void inputData(float data[][days]) {

    cout << "Enter defect percentage for each shift over 7 days:\n";

    for (int i = 0; i < shifts; i++) {
        cout << endl;
        for (int j = 0; j < days; j++) {
        Input:
            float percent;
            cout << "Enter defect % for Shift " << i + 1 << " on Day " << j + 1 << ": ";
            cin >> percent;

            if (percent >= 0 && percent <= 100) {
                data[i][j] = percent;
            }
            else {
                cout << "\nInvalid input! Enter percentage between 0 and 100.\n\n";
                goto Input;
            }
        }
    }
}

void calculateAverages(float data[][days]) {

    cout << "\n\nAverage defects per Shift:\n\n";

    for (int i = 0; i < shifts; i++) {
        float sum = 0;
        for (int j = 0; j < days; j++) {
            sum += data[i][j];
        }
        float avg = sum / days;
        cout << "Shift " << i + 1 << " Average Defect %: " << avg;

        if (avg > 10) {
            cout << "\n It is a critical shift.\n";
        }

        cout << endl;
    }

    cout << "\n\nAverage defects per Day:\n\n";

    for (int j = 0; j < days; j++) {
        float sum = 0;
        for (int i = 0; i < shifts; i++) {
            sum += data[i][j];
        }
        float avg = sum / shifts;
        cout << "Day " << j + 1 << " Average Defect %: " << avg << endl;
    }
}

int main() {

    float data[shifts][days];

    inputData(data);
    calculateAverages(data);
}
