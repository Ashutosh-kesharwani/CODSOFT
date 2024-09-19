#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>  // For input validation

using namespace std;

int main() {
    char playAgain;

    do {
        cout << "\n\nWelcome to the Number Guessing Game: **Defeat The Dragon**!!!" << endl;
        cout << "To Save The Village, You Must Guess The Dragon's Health Correctly!" << endl;
        cout << "Use Your Magical Spell Power to Defeat the Dragon (:>>>!" << endl;
        cout << "If Your Spell Power Matches The Dragon's Health, The Dragon Will Be Vanquished." << endl;
        cout << "Become The Hero and Protect The Village From Destruction!" << endl;
        cout << "-----------------------------------------------------------" << endl;

        srand((unsigned int)(time(NULL)));
        int health = (rand() % 1000) + 1;  // Dragon's health between 1 and 1000
        int spellPower;

        while (true) {
            cout << "\nGuess the Dragon's Health (between 1 and 1000) using your Spell Power: ";

            // Input validation to ensure the user enters a valid number
            while (!(cin >> spellPower) || spellPower < 1 || spellPower > 1000) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input! Please enter a number between 1 and 1000: ";
            }

            if (spellPower > health) {
                cout << "Your Spell Power is too strong! The Dragon's health is lower. (Hint: Try a smaller number)" << endl;
                cout << "The Dragon roars in defiance as your spell misses!" << endl;
            }
            else if (spellPower < health) {
                cout << "Your Spell Power is too weak! The Dragon's health is higher. (Hint: Try a larger number)" << endl;
                cout << "The Dragon smirks as your spell barely touches it!" << endl;
            }
            else {
                cout << "Hurray! Your Spell Power matches the Dragon's health!" << endl;
                cout << "You defeated the Dragon and saved the village! You're a true hero!" << endl;
                break;
            }
        }

       // Asks if player want to play again
        cout << "\nDo you want to play again and fight another dragon? (y/n): ";
        cin >> playAgain;

        // Input validation for replay choice
        while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
            cout << "Invalid input! Please enter 'y' for yes or 'n' for no: ";
            cin >> playAgain;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThank you for playing! The village is safe thanks to your bravery. See you next time, hero!" << endl;
    return 0;
}
