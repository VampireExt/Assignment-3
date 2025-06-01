#include<iostream>
using namespace std;

const int patients = 5, days = 7;


void inputData(char data[][days]) {

	cout << "Input record of the patients: \n\n";

    

    for (int i = 0; i < patients; i++) {
        cout << endl;
        for (int j = 0; j < days; j++) {

        Input:
            char input;
            cout << "Enter status (S/C/R) for Patient " << i + 1 << " on Day " << j + 1 << ": ";
            cin >> input;

            if (input == 'S' || input == 'C' || input == 'R'||input=='s' || input == 'c' || input == 'r') {
                data[i][j] = input;
            }
            else {
                cout << "\nInvalid input!.Please enter only S, C, or R.\n\n";
                goto Input;  
            }
        }
    }


}
void countingInEachCategory(char data[][days]) {

    int sCount = 0, rCount = 0, cCount = 0;
    for (int i = 0; i < patients; i++) {

        for (int j = 0; j < days; j++) {
            if (data[i][j] == 'r' || data[i][j] == 'R') {
                rCount++;
            }
            else if (data[i][j] == 's' || data[i][j] == 'S') {
                sCount++;
            }
             else if (data[i][j] == 'c' || data[i][j] == 'C') {
                cCount++;
            }
             
        }
    }
    cout << endl;
    int criticalSum = 0;
    for (int i = 0; i < patients; i++) {
        criticalSum = 0;
        for (int j = 0; j < days; j++) {
            if (data[i][j] == 'c' || data[i][j] == 'C') {
                criticalSum++;
            }
        }
        cout << "Patient: " << i + 1 << " remained in critical for: " << criticalSum << " days" << endl;
    }

    cout << "\nPatients in each status Category: \n\n";
    cout << "Stable: " << sCount << endl;
    cout << "Recovered: " << rCount << endl;
    cout << "Critical: " << cCount << endl;

    
}


int main() {


	char data[patients][days];

	inputData(data);
    countingInEachCategory(data);
}