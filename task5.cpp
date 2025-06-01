#include<iostream>
using namespace std;

const int teams = 6, rounds = 4;

void inputData(int data[][rounds]) {

    cout << "Enter scores of the teams:\n\n";

    for (int i = 0; i < teams; i++) {
        cout << endl;
        for (int j = 0; j < rounds; j++) {
            cout << "Enter score of team " << i + 1 << " in round " << j + 1 << ": ";
            cin >> data[i][j];
        }
    }
}

void calculations(int data[][rounds]) {

    int totalScore[teams] ;

    cout << "\nCalculating total scores of all teams:\n\n";

    for (int i = 0; i < teams; i++) {
        int sum = 0;
        for (int j = 0; j < rounds; j++) {
            sum += data[i][j];
        }
        totalScore[i] = sum;
        cout << "Team " << i + 1 << " scored: " << sum << endl;
    }

    int max = totalScore[0], winnerIndex = 0;

    for (int i = 1; i < teams; i++) {

        if (totalScore[i] > max) {
            max = totalScore[i];
            winnerIndex = i;
        }
    }

    int secondMax = INT_MIN, runnerUpIndex = -1;

    for (int i = 0; i < teams; i++) {

        if (i == winnerIndex) {
            continue;
        }

        else if(totalScore[i] > secondMax) {
            secondMax = totalScore[i];
            runnerUpIndex = i;
        }
    }

    cout << "\nThe winner is Team " << winnerIndex + 1 << " with " << max << " score." << endl;
    cout << "The runner-up is Team " << runnerUpIndex + 1 << " with " << secondMax << " score." << endl;

    cout << "\nTeams that scored 10 or less in any round:\n\n";
    for (int i = 0; i < teams; i++) {
        for (int j = 0; j < rounds; j++) {
            if (data[i][j] <= 10) {
                cout << "Team " << i + 1 << " scored " << data[i][j] << " in round " << j + 1 << endl;
                break;
            }
        }
    }
}

int main() {

    int data[teams][rounds];

    inputData(data);
    calculations(data);
}
