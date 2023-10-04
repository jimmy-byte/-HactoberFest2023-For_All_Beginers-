// In this code, we have to guess the number between the limit
// I have defined 3 level of difficulties that seperates from the guessing limits
// If the limit cross, it terminates the program displaying the correct number

#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <vector>
#include <string>
#include <limits>    // For numeric_limits
#include <algorithm>  // For sort
using namespace std;

class NumberGuessingGame {
private:
    int secretNumber;
    int attempts;
    int maxAttempts;
    string playerName;
    vector<pair<string, int>> highScores;

public:
    NumberGuessingGame() {
        srand(static_cast<unsigned>(time(0)));  // Seed the random number generator
        secretNumber = rand() % 100 + 1;       // Generate a random number between 1 and 100
        attempts = 0;
        maxAttempts = 7; // Default maximum attempts
    }

    void setPlayerName() {
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, playerName);
    }

    void setDifficulty() {
        cout << "Choose difficulty level (1, 2, 3):" << endl;
        cout << "1. Easy (10 attempts)" << endl;
        cout << "2. Medium (7 attempts)" << endl;
        cout << "3. Hard (5 attempts)" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                maxAttempts = 10;
                break;
            case 2:
                maxAttempts = 7;
                break;
            case 3:
                maxAttempts = 5;
                break;
            default:
                cout << "Invalid choice. Defaulting to Medium difficulty." << endl;
        }
    }

    void playGame() {
        cout << "Welcome, " << playerName << "! Let's play the Number Guessing Game!" << endl;
        cout << "I'm thinking of a number between 1 and 100." << endl;

        while (attempts < maxAttempts) {
            int guess;
            cout << "Attempt " << attempts + 1 << "/" << maxAttempts << " - Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else if (guess > secretNumber) {
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations, " << playerName << "! You guessed the correct number, which is " << secretNumber << endl;
                cout << "It took you " << attempts << " attempts." << endl;
                updateHighScores();
                break;
            }
        }

        if (attempts >= maxAttempts) {
            cout << "Sorry, " << playerName << "! You've reached the maximum number of attempts." << endl;
            cout << "The correct number was " << secretNumber << endl;
        }
    }

    void updateHighScores() {
        highScores.push_back(make_pair(playerName, attempts));
        sort(highScores.begin(), highScores.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });

        if (highScores.size() > 5) {
            highScores.pop_back();
        }

        cout << "High Scores:" << endl;
        for (int i = 0; i < highScores.size(); ++i) {
            cout << i + 1 << ". " << highScores[i].first << " - " << highScores[i].second << " attempts" << endl;
        }
    }
};

int main() {
    NumberGuessingGame game;
    game.setPlayerName();  // calling the function
    game.setDifficulty();
    game.playGame();

    return 0;
}
