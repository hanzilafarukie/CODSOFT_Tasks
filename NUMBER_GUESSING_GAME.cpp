#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;
    cout << "Welcome to the Guess the Number Game!\n";
    cout << "I have selected a number between 1 and 100. Try to guess it.\n";

    do {
     
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        if (userGuess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        }

    } 
    while (userGuess != secretNumber);

    return 0;
}
