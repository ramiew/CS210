#include <iostream>
#include <iomanip>
#include "Bank.h"
using namespace std;

//KATHLEEN CRUZ
//1/28/2023
//PROJECT TWO AIRGEAD BANKING

//Variables used
double Investment; // For Investment Input
double Deposit; // For Deposit Input
double Interest; // For Interest Rates Input
int Years; // For number of years Input
string input; // For user reply Input


Bank Bank1; // Bank Object Used for calculations

// Function to return a string of length n, of each character c
string nCharString(size_t n, char c) {
    string charString;  // Initialize string

    // Loop n amount of times and append c to charString n times
    for (int i = 0; i < n; ++i) {
        charString.push_back(c);
    }
    return charString;
}

// Function to Display Initial Input Menu
void displayMenu() {
   // Top Border and Title
    cout << nCharString(32, '*') << endl;
    cout << nCharString(10, '*') << "Data Input" << nCharString(12, '*') << endl;

    // Menu Options
    
    // Ask for Initial Investment
    cout << "Initial Investment Amount: $";
    cin >> Investment;
    // If Less than 0, set to default
    if (Investment < 0) {
        Bank1.setInitialInvestment();
    }
    // Else set to what was keyed in
    else {
        Bank1.setInitialInvestment(Investment);
    }

    // Ask for Monthly Deposit
    cout << "Monthly Deposit: $";
    cin >> Deposit;
    // If Less than 0, set to default
    if (Deposit < 0) {
        Bank1.setMonthlyDeposit();
    }
    // Else set to what was keyed in
    else {
        Bank1.setMonthlyDeposit(Deposit);
    }

    // Ask for Annual Interest
    cout << "Annual Interest: %";
    cin >> Interest;
    // If Less than 0, set to default
    if (Interest < 0) {
        Bank1.setAnnualInterest();
    }
    // Else set to what was keyed in
    else {
        Bank1.setAnnualInterest(Interest);
    }

    // Ask for Number of Years for investment
    cout << "Number of years: ";
    cin >> Years;
    // If Less than 0, set to default
    if (Years < 0) {
        Bank1.setNumberYears();
    }
    // Else set to what was keyed in
    else {
        Bank1.setNumberYears(Years);
    }

    // Prompt for input to continue
    cout << "Press any key to continue..." << endl;
    cin >> input;
}

// Function used to display Report One and Report Two
void reports() {

    // Report One - Display Balance and Interests Without Additional Monthly Deposits
    // Top Border
    cout << "  Balance and Interest Without Additional Monthly Deposits  " << endl;
    cout << nCharString(60, '=') << endl;
    cout << "  Year     Year End Balance       Year End Earned Interest" << endl;
    cout << nCharString(60, '-') << endl;
    
    double totalAmount = Bank1.getInitialInvestment(); // Total Amount of Investment
    
    // For loop to calculate how much your interest is earned and year end balance
    for (int i = 1; i <= Bank1.getNumberYears(); ++i) {
        double InterestEarned = (totalAmount * ((Bank1.getAnnualInterest() / 100)));
        double YearEndBalance = totalAmount + InterestEarned;
        totalAmount = YearEndBalance;
        
        // OutputData
        cout << i << nCharString(21, ' ') << "$" << fixed << setprecision(2) << totalAmount << "\t\t\t" << "$" << InterestEarned << endl;
        cout << endl;  //Start new line
    }

    cout << endl; // Start New Line

    // Report Two - Display Balance and Interests With Additional Monthly Deposits
    // Top Border
    cout << "   Balance and Interest With Additional Monthly Deposits   " << endl;
    cout << nCharString(60, '=') << endl;
    cout << "  Year     Year End Balance       Year End Earned Interest" << endl;
    cout << nCharString(60, '-') << endl;

    if (Bank1.getMonthlyDeposit() == 0) {
        Bank1.setMonthlyDeposit(50);
    }

    totalAmount = Bank1.getInitialInvestment(); // Total Amount of Investment

    // For loop to calculate how much your interest is earned and year end balance
    double MonthlyInterest; // How much interest earned in the month
    for (int i = 1; i <= Bank1.getNumberYears(); ++i) {
        double TotalInterest = 0; // Total Interest for the year
        for (int j = 1; j <= 12; ++j) {  // 2nd For loop to iterate through monthly Interest rates and add to total
            MonthlyInterest = (totalAmount + Bank1.getMonthlyDeposit()) * ((Bank1.getAnnualInterest() / 100) / 12);
            TotalInterest += MonthlyInterest;
            totalAmount += Bank1.getMonthlyDeposit() + MonthlyInterest;
        }
        // Output Data
        cout << i << nCharString(21, ' ') << "$" << fixed << setprecision(2) << totalAmount << "\t\t\t" << "$" << TotalInterest << endl;
        cout << endl; // Start new line

    }
    // Start new line
    cout << endl;

    // Ask if They would like to go to main menu to try different options
    cout << "Would you like to try different options?  Y or N" << endl;
    cin >> input;
    //If yes, repeat menu display and show new reports
    if (input == "y" || input == "Y") {
        displayMenu();
        reports();
    } 
}

int main() {
    displayMenu();
    reports();
    
}