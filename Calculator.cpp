#include <iostream>

int main() {
    char operation;
    double num1, num2, result;

    std::cout << "Welcome to the Basic Calculator!\n";

    // Input first number
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    // Input second number
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Choose operation
    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform calculation based on the chosen operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
            } else {
                std::cout << "Error: Cannot divide by zero!\n";
            }
            break;
        default:
            std::cout << "Error: Invalid operation!\n";
    }

    return 0;
}
