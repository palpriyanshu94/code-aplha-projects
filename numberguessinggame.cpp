#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Your guess is too low. Try again." << endl;
        } else {
            cout << "Your guess is too high. Try again." << endl;
        }
    }

    return 0;
}