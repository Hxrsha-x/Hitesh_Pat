#include <iostream>
using namespace std;

class TeamB; // Forward declaration of class TeamB

class TeamA {
private:
    int runs[5];
    int totalRuns;

public:
    void setRuns() {
        cout << "***Team A***\n";
        cout << "Enter the runs scored in each over:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Over " << i + 1 << ": ";
            cin >> runs[i];
        }
    }

    int calculateTotalRuns() {
        totalRuns = 0;
        for (int i = 0; i < 5; i++) {
            totalRuns += runs[i];
        }
        return totalRuns;
    }

    friend void matchResult(TeamA&, TeamB&);
};

class TeamB {
private:
    int runs[5];
    int totalRuns;

public:
    void setRuns() {
        cout << "***Team B***\n";
        cout << "Enter the runs scored in each over:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Over " << i + 1 << ": ";
            cin >> runs[i];
        }
    }

    int calculateTotalRuns() {
        totalRuns = 0;
        for (int i = 0; i < 5; i++) {
            totalRuns += runs[i];
        }
        return totalRuns;
    }

    friend void matchResult(TeamA&, TeamB&);
};

void matchResult(TeamA& teamA, TeamB& teamB) {
    int totalRunsA = teamA.calculateTotalRuns();
    int totalRunsB = teamB.calculateTotalRuns();

    cout << "Total runs scored by Team A: " << totalRunsA << endl;
    cout << "Total runs scored by Team B: " << totalRunsB << endl;

    if (totalRunsA > totalRunsB) {
        cout << "Team A wins!" << endl;
    } else if (totalRunsA < totalRunsB) {
        cout << "Team B wins!" << endl;
    } else {
        cout << "The match is a tie!" << endl;
    }
}

int main() {
    int overs;
    cout << "Enter the number of overs per team: ";
    cin >> overs;

    TeamA teamA;
    TeamB teamB;

    teamA.setRuns();
    teamB.setRuns();

    matchResult(teamA, teamB);

    return 0;
}
