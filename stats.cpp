#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>  // getch() & system("cls")
#include <stdexcept>

using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class ScoreEntry {
private:
    string name;
    int score;
    char status; // '$' pentru aprobat, '#' pentru în așteptare

public:
    ScoreEntry() : name(""), score(0), status('#') {}
    ScoreEntry(const string& n, int s, char st) : name(n), score(s), status(st) {}

    string getName() const { return name; }
    int getScore() const { return score; }
    char getStatus() const { return status; }

    void setName(const string& n) { name = n; }
    void setScore(int s) { score = s; }
    void setStatus(char st) { status = st; }
};

void clrscr() {
    system("cls");
}

vector<ScoreEntry> loadScores() {
    vector<ScoreEntry> scores;
    ifstream file("scores.txt");
    if (!file.is_open()) {
        throw runtime_error("Failed to open scores.txt for reading.");
    }

    char symbol;
    string name;
    int score;
    while (file >> symbol >> name >> score) {
        scores.push_back(ScoreEntry(name, score, symbol));
    }

    if (file.bad()) {
        throw runtime_error("Error occurred while reading from scores.txt.");
    }

    return scores;
}

void saveScoresToFile(const vector<ScoreEntry>& scores) {
    ofstream file("scores.txt");
    if (!file.is_open()) {
        throw runtime_error("Failed to open scores.txt for writing.");
    }
    for (const auto& entry : scores) {
        file << entry.getStatus() << " " << entry.getName() << " " << entry.getScore() << endl;
    }
    if (file.fail()) {
        throw runtime_error("Error occurred while writing to scores.txt.");
    }
}

void displayLeaderboard() {
    try {
        clrscr();
        vector<ScoreEntry> scores = loadScores();

        vector<ScoreEntry> approved;
        for (const auto& entry : scores) {
            if (entry.getStatus() == '$') approved.push_back(entry);
        }

        sort(approved.begin(), approved.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
            return a.getScore() > b.getScore();
        });

        cout << YELLOW << "   ________________________________\n" << RESET;
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "         "<<BLUE<<"Leaderboard            \n";
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |________________________________\n" << RESET ;
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |" << RESET << "  "<<BLUE<<"Name:"<<RESET<<RED<<" Score                   \n";
        cout << YELLOW << "  |" << RESET << "                                \n";

        for (const auto& entry : approved) {
            cout << YELLOW << "  |" << RESET << "  " <<BLUE<< entry.getName() <<RESET<< ": " <<RED<< entry.getScore() << endl;
        }
        cout << YELLOW << "  |" << RESET << "                                \n";
        cout << YELLOW << "  |Press any key to return to menu         ";
        getch();
    }
    catch (const exception& ex) {
        cout << "\nError: " << ex.what() << "\nPress any key to return...";
        getch();
    }
}

void viewGameHistory() {
    try {
        clrscr();
        vector<ScoreEntry> scores = loadScores();
        string name;
        cout << YELLOW << " |            Enter player name: ";

        cin >> name;

        cout << YELLOW << " |                                \n";
        cout << YELLOW << " |          Game History for " << name << "     \n";
        cout << YELLOW << " |                                \n";
        bool found = false;
        for (const auto& entry : scores) {
            if (entry.getStatus() == '$' && entry.getName() == name) {
                cout << YELLOW << " |          Score: " << entry.getScore() << endl;
                found = true;
            }
        }
        if (!found) {
            cout << YELLOW << " |         No scores found for this player.\n";
        }

        cout << YELLOW << " |   Press any key to return to menu...";
        getch();
    }
    catch (const exception& ex) {
        cout << "\nError: " << ex.what() << "\nPress any key to return...";
        getch();
    }
}

void verifyScores() {
    try {
        vector<ScoreEntry> scores = loadScores();
        bool modified = false;

        vector<ScoreEntry> newScores;

        int pendingCount = 0;
        for (const auto& e : scores)
            if (e.getStatus() == '#') pendingCount++;

        if (pendingCount == 0) {
            cout << YELLOW << "\n  |  No pending scores to verify.\n";
            cout << YELLOW << "  | Press any key to return to menu...";
            getch();
            return;
        }

        for (auto& entry : scores) {
            if (entry.getStatus() == '#') {
                clrscr();
                cout << YELLOW << "  |    Verify/Save Scores\n";
                cout << YELLOW << "  |_________________________\n" << RESET ;
                cout << YELLOW << "  |    Name: " << entry.getName() << "\n";
                cout << YELLOW << "  |    Score: " << entry.getScore() << "\n";
                cout << YELLOW << "  |    Keep this score? (y/n): ";

                char choice;
                while (true) {
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                        break;
                    else
                        cout << YELLOW << "  |    Invalid input. Please enter y or n: ";
                }

                if (choice == 'y' || choice == 'Y') {
                    entry.setStatus('$');
                    newScores.push_back(entry);
                    modified = true;
                } else {
                    modified = true;
                }

                cout << YELLOW << "  |    Press any key for next score...";
                getch();
            } else {
                newScores.push_back(entry);
            }
        }

        clrscr();
        if (modified) {
            saveScoresToFile(newScores);
            cout << YELLOW << " |    Scores updated.\n";
        }
        cout << YELLOW << " |    No more pending scores.\n";
        cout << YELLOW << " |    Press any key to return to menu...";
        getch();
    }
    catch (const exception& ex) {
        cout << "\nError: " << ex.what() << "\nPress any key to return to menu...";
        getch();
    }
}

bool checkPassword() {
    const string SECRET_CODE = "bepa123";
    string input;

    cout << "Code: ";
    cin >> input;

    if (input == SECRET_CODE) {
        return true;
    } else {
        cout << "  | Wrong\n";
        getch();
        return false;
    }
}

int main() {
    try {
        while (true) {
            clrscr();

            cout << YELLOW << "   ________________________________\n" << RESET;
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "         "<<BLUE<<"Score Manager          \n";
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "         "<<BLUE<<"Albert-Adrian          \n";
            cout << YELLOW << "  |" << RESET << "             "<<BLUE<<"Popa               \n";
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "           "<<YELLOW<<"--and--              \n";
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "         "<<RED<<" Bele Marko             \n";
            cout << YELLOW << "  |________________________________\n" << RESET ;
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "           "<<BLUE<<"*--Menu--*           \n";
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |" << RESET << "  "<<BLUE<<"1. "<<RESET<<YELLOW<<"Display Leaderboard        \n";
            cout << YELLOW << "  |" << RESET << "  "<<YELLOW<<"2. "<<RESET<<YELLOW<<"View Game History          \n";
            cout << YELLOW << "  |" << RESET << "  "<<RED<<"3. "<<RESET<<YELLOW<<"Exit                       \n";
            cout << YELLOW << "  |" << RESET << "                                \n";
            cout << YELLOW << "  |     Choose an option: ";

            char choice = getch();
            switch (choice) {
                case '1': displayLeaderboard(); break;
                case '2': viewGameHistory(); break;
                case '4':
                    if (checkPassword()) {
                        verifyScores();
                    }
                    break;
                case '3': return 0;
                default:
                    cout << "\nInvalid option. Try again.\n";
                    getch();
            }
        }
    }
    catch (const exception& ex) {
        cout << "Fatal error: " << ex.what() << endl;
        cout << "Press any key to exit...";
        getch();
        return 1;
    }
}