#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Prompt the user to enter two numbers
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Prompt the user to choose an operation
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    // Perform the chosen operation
    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << std::endl;
            } else {
                cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << std::endl;
            break;
    }

    return 0;
}
