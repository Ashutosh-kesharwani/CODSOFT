#include<iostream>
#include<cmath>
#include<limits>
using namespace std;

#define PI 3.14159265 // Define the value of π

void showMenu() {
    cout << "\nWelcome to the Advanced Calculator!" << endl;
    cout << "Select an operation to perform:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square of a Number" << endl;
    cout << "6. Square Root of a Number" << endl;
    cout << "7. Modulo" << endl;
    cout << "8. Exponentiation (n1^n2)" << endl;
    cout << "9. Sine (sin(n1) in degrees)" << endl;  // Update this to clarify degrees
    cout << "10. Cosine (cos(n1))" << endl;
    cout << "11. Tangent (tan(n1))" << endl;
    cout << "12. Exit\n" << endl;
}

int main() {
    char useAgain;
    int choice;
    bool isSingleInput;
    
    do {
        showMenu();
        cout << "Enter your choice (1-12): ";
        while (!(cin >> choice) || choice < 1 || choice > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a valid choice (1-12): ";
        }

        double n1, n2;
        isSingleInput = (choice == 5 || choice == 6 || choice >= 9); // Operations with single input

        // Get user inputs
        if (isSingleInput) {
            cout << "Enter the number: ";
            while (!(cin >> n1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number: ";
            }
        } else if (choice != 12) {
            cout << "Enter the first number: ";
            while (!(cin >> n1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number: ";
            }
            cout << "Enter the second number: ";
            while (!(cin >> n2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number: ";
            }
        }

        // Perform the chosen operation
        switch (choice) {
            case 1: cout << "The result of addition is: " << (n1 + n2) << endl; break;
            case 2: cout << "The result of subtraction is: " << (n1 - n2) << endl; break;
            case 3: cout << "The result of multiplication is: " << (n1 * n2) << endl; break;
            case 4: 
                while (n2 == 0) {
                    cout << "Error! Division by zero is not allowed. Please enter a non-zero second number: ";
                    cin >> n2;
                }
                cout << "The result of division is: " << (n1 / n2) << endl; 
                break;
            case 5: cout << "The square of the number is: " << (n1 * n1) << endl; break;
            case 6: 
                while (n1 < 0) {
                    cout << "Error! Square root of a negative number is not defined. Please enter a non-negative number: ";
                    cin >> n1;
                }
                cout << "The square root of the number is: " << sqrt(n1) << endl; 
                break;
            case 7: cout << "The result of modulo is: " << (int(n1) % int(n2)) << endl; break;
            case 8: cout << "The result of exponentiation (n1^n2) is: " << pow(n1, n2) << endl; break;
            case 9: 
                cout << "The sine of " << n1 << " degrees is: " << sin(n1 * PI / 180) << endl; 
                break;
            case 10: cout << "The cosine of the number is: " << cos(n1) << endl; break;
            case 11: cout << "The tangent of the number is: " << tan(n1) << endl; break;
            case 12: cout << "Exiting the calculator..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }

        if (choice != 12) {
            cout << "\nDo you want to perform another operation? (y/n): ";
            cin >> useAgain;
            while (useAgain != 'y' && useAgain != 'Y' && useAgain != 'n' && useAgain != 'N') {
                cout << "Invalid input! Please enter 'y' for yes or 'n' for no: ";
                cin >> useAgain;
            }
        }

    } while (useAgain == 'y' || useAgain == 'Y');

    cout << "Thank you for using the calculator! Have a great day!" << endl;
    return 0;
}
