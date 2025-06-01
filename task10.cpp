#include<iostream>
using namespace std;

const int candidates = 4, stations = 6;

void inputData(int data[][stations]) {

    cout << "Enter number of votes each candidate received at each polling station:\n";

    for (int i = 0; i < candidates; i++) {
        cout << "\nCandidate " << i + 1 << ":\n";
        for (int j = 0; j < stations; j++) {
        Input:
            int votes;
            cout << "Enter votes at Station " << j + 1 << ": ";
            cin >> votes;

            if (votes >= 0) {
                data[i][j] = votes;
            }
            else {
                cout << "\nInvalid input! Enter non-negative votes only.\n\n";
                goto Input;
            }
        }
    }
}

void calculateAndResult(int data[][stations]) {

    int candidateTotal[candidates] = { 0 };
    int stationTotal[stations] = { 0 };

    cout << "\n\nTotal Votes per Candidate:\n\n";
    for (int i = 0; i < candidates; i++) {
        for (int j = 0; j < stations; j++) {
            candidateTotal[i] += data[i][j];
        }
        cout << "Candidate " << i + 1 << ": " << candidateTotal[i] << endl;
    }

    cout << "\nTotal Votes per Polling Station:\n\n";
    for (int j = 0; j < stations; j++) {
        for (int i = 0; i < candidates; i++) {
            stationTotal[j] += data[i][j];
        }
        cout << "Station " << j + 1 << ": " << stationTotal[j];
        if (stationTotal[j] < 100) {
            cout << "  <-- Voter turnout below 100!";
        }
        cout << endl;
    }

    
    int maxVotes = 0, temp = 0;
    for (int i = 0; i < candidates; i++) {
        if (candidateTotal[i] > maxVotes) {
            maxVotes = candidateTotal[i];
            temp = i;
        }
    }

    cout << "\nWinner is candidate: "<<temp+1<<" with votes: " << maxVotes << " :\n\n";
   
}

int main() {

    int data[candidates][stations];

    inputData(data);
    calculateAndResult(data);
}
