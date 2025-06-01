#include<iostream>
using namespace std;

const int students = 3, subjects = 5;
const int coloumn = subjects + 3;


void inputData(int data[students][coloumn]) {
    for (int i = 0; i < students; i++) {
        cout << "Enter roll no of student " << i + 1 << ": ";
        cin >> data[i][0];
        cout << endl;

        int sum = 0;
        for (int j = 1; j <= subjects; j++) {
            cout << "Enter marks for Subject " << j << ": ";
            cin >> data[i][j];
            sum += data[i][j];
        }

        data[i][subjects + 1] = sum;
        data[i][subjects + 2] = sum / subjects;
        cout << endl;
    }
}


void displayResults(int data[students][coloumn]) {
    cout << "\nRoll\tPhy\tChem\tBio\tEng\tUrdu\tTotal\tAvg\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < coloumn; j++) {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

void findTopScorer(int data[students][coloumn]) {
    int max = -1;

    int topperIndex = -1;

    for (int i = 0; i < students; i++) {
        if (data[i][subjects + 1] > max) {
            max = data[i][subjects + 1];
            topperIndex = i;
        }
    }

    cout << "\nRoll no: " << data[topperIndex][0]
        << " is the topper with the total marks of: " << max << endl << endl;
}


void displayGrades(int data[students][coloumn]) {
    cout << "Grades of students:\n";
    for (int i = 0; i < students; i++) {
        int avg = data[i][coloumn - 1];
        char g;

        if (avg >= 90) {
            g = 'A';
        }
        else if (avg >= 80) {
            g = 'B';
        }
        else if (avg >= 70) {
            g = 'C';
        }
        else if (avg >= 60) {
            g = 'D';
        }
        else {
            g = 'F';
        }

        cout << "Student " << data[i][0] << " has Grade: " << g << endl;
    }
}

int main() {
    int data[students][coloumn];

    cout << "Subject 1: Physics\n";
    cout << "Subject 2: Chemistry\n";
    cout << "Subject 3: Biology\n";
    cout << "Subject 4: English\n";
    cout << "Subject 5: Urdu\n\n";

    inputData(data);
    displayResults(data);
    findTopScorer(data);
    displayGrades(data);

    return 0;
}
