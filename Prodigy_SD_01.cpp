// Prodigy_SD_01.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double cToF(double celsius);
double fToC(double fahrenheit);
double cToK(double celsius);
double kToC(double kelvin);
double fToK(double fahrenheit);
double kToF(double kelvin);

// Function to convert Celsius to Fahrenheit
double cToF(double celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

// Function to convert Fahrenheit to Celsius
double fToC(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Kelvin
double cToK(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
double kToC(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fToK(double fahrenheit) {
    return cToK(fToC(fahrenheit));
}

// Function to convert Kelvin to Fahrenheit
double kToF(double kelvin) {
    return cToF(kToC(kelvin));
}

int main() {

    int selection;
    double inputTemp, outputTemp; // User's input and functions output variables

    do {
        // Display Menu
        cout << endl;
        cout << "Welcome to Temperature Converter Menu!" << endl;
        cout << "Choose one number of the Menu" << endl << endl;
        cout << " 1 - Celsius to Fahrenheit \n";
        cout << " 2 - Fahrenheit to Celsius \n";
        cout << " 3 - Celsius to Kelvin \n";
        cout << " 4 - Kelvin to Celsius \n";
        cout << " 5 - Fahrenheit to Kelvin \n";
        cout << " 6 - Kelvin to Fahrenheit \n";
        cout << " 0 - Exit" << endl;

        cout << endl << "Enter your choice: ";
        cin >> selection;


        //buffer in case there is an error in the user's entry
        if (cin.fail() || selection < 0 || selection > 6) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid selection. Please choose a number between 0 and 6." << endl;
            continue;
        }

        if (selection == 0) {
            cout << "Exiting the program." << endl;
            break;
        }

        cout << "Enter the temperature: ";
        cin >> inputTemp;

        //buffer in case there is an error in the user's entry
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid temperature input. Please enter a valid number." << endl;
            continue;
        }

        switch (selection) {
        case 1:
            outputTemp = cToF(inputTemp);
            cout << "Temperature in Fahrenheit: " << fixed << setprecision(2) << outputTemp << endl;
            break;
        case 2:
            outputTemp = fToC(inputTemp);
            cout << "Temperature in Celsius: " << fixed << setprecision(2) << outputTemp << endl;
            break;
        case 3:
            outputTemp = cToK(inputTemp);
            cout << "Temperature in Kelvin: " << fixed << setprecision(2) << outputTemp << endl;
            break;
        case 4:
            if (inputTemp < 0) {
                cout << "Kelvin temperature cannot be negative. Please enter a valid temperature." << endl;
                continue;
            }
            outputTemp = kToC(inputTemp);
            cout << "Temperature in Celsius: " << fixed << setprecision(2) << outputTemp << endl;
            break;
        case 5:
            outputTemp = fToK(inputTemp);
            cout << "Temperature in Kelvin: " << fixed << setprecision(2) << outputTemp << endl;
            break;
        case 6:
            if (inputTemp < 0) {
                cout << "Kelvin temperature cannot be negative. Please enter a valid temperature." << endl;
                continue;
            }
            outputTemp = kToF(inputTemp);
            cout << "Temperature in Fahrenheit: " << fixed << setprecision(2) << outputTemp << endl;
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }

        //it will ask user to continue with the application or not
        char anotherConversion;
        cout << "Would you like to perform another conversion? (Y/N): ";
        cin >> anotherConversion;

        if (anotherConversion != 'y' && anotherConversion != 'Y') {
            cout << "Exiting the program." << endl;
            break;
        }

    } while (true);

    cout << "Thank you for using the Temperature Converter Program" << endl;

    return 0;
}
