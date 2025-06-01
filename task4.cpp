#include<iostream>
using namespace std;

const int regions = 5, temperatures = 5;


void inputData(float data[][temperatures]) {

    cout << "Input record of the weather: \n";

    for (int i = 0; i < regions; i++) {
        cout << endl;
        for (int j = 0; j < temperatures; j++) {
            cout << "Enter reading: " << j + 1 << " of the region: " << i + 1<<": ";
            cin >> data[i][j];
        }
    }


}
void calculations(float data[][temperatures]) {
    
    cout << "\n\nCalculating average temperature in each region: \n\n";
    float rowSum = 0;
    for (int i = 0; i < regions; i++) {
        rowSum = 0;
        for (int j = 0; j < temperatures; j++) {
            rowSum += data[i][j];
        }
        cout << "Average temperature of region: " << i + 1 << " is: " << rowSum / temperatures << endl;
    }
    float hot = INT_MIN, cold = INT_MAX;
    int hRow, hColoumn, cRow, cColoumn;

    for (int i = 0; i < regions; i++) {
        for (int j = 0; j < temperatures; j++) {

            if (hot < data[i][j]) {
                hot = data[i][j];
                hRow = i+1;
                hColoumn = j+1;
            }
            if (cold > data[i][j]) {
                
                cold = data[i][j];
                cRow = i + 1;
                cColoumn = j + 1;
            }
        }
    }
    cout << "\nHottest = " << hot << "  at Row: " << hRow << " and Coloumn: " << hColoumn << endl;
    cout << "\nColdest = " << cold << "  at Row: " << cRow << " and Coloumn: " << cColoumn << endl;

}


int main() {


    float data[regions][temperatures];
    inputData(data);
    calculations(data);
    
}