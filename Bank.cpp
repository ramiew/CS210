#include "Bank.h"
#include <iostream>
using namespace std;

// Function to get Initial Investment
double Bank::getInitialInvestment() {
	return m_InitialInvestment;
}

// Function to set Initial Investment
void Bank::setInitialInvestment(double t_Investment) {
	m_InitialInvestment = t_Investment;
}

// Function to get Monthly Deposit
double Bank::getMonthlyDeposit() {
	return m_MonthlyDeposit;
}

// Function to set Monthly Deposit
void Bank::setMonthlyDeposit(double t_Deposit) {
	m_MonthlyDeposit = t_Deposit;
}

// Function to get Annual Interest
double Bank::getAnnualInterest() {
	return m_AnnualInterest;
}

// Function to set Annual Interest
void Bank::setAnnualInterest(double Interest) {
	m_AnnualInterest = Interest;
}

// Function to get Number of Years
int Bank::getNumberYears() {
	return m_NumberYears;
}

//Function to set Number of Years
void Bank::setNumberYears(int t_Years) {
	m_NumberYears = t_Years;
}