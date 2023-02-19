#pragma once
#ifndef BANK_H
#define BANK_H
class Bank
{

// Public Variables
public:
	
	double getInitialInvestment(); // Get Initial Investment
	void setInitialInvestment(double t_Investment = 0); // Set Initial Investment, default set to 0.
	double getMonthlyDeposit(); // Get monthly Deposit
	void setMonthlyDeposit(double t_Deposit = 0); // Set Monthly Deposit, default set to 0.
	double getAnnualInterest(); // Get Annual Interest
	void setAnnualInterest(double t_Interest = 0); //Set Annual Interest, default set to 0.
	int getNumberYears(); // Get number of years for investment
	void setNumberYears(int t_Years = 1); //Set Number of Years, default set to 1.

// Private Variables
private:

	double m_InitialInvestment; //Initial Investment
	double m_MonthlyDeposit; //Monthly Deposit 
	double m_AnnualInterest; //Annual Interest
	int m_NumberYears; //Number of Years for investment
};

#endif
