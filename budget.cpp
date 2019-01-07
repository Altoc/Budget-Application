/*
		*Ian Whitesel
		*Budget Application Func Definitions
		*01/04/2019
*/

#include <iostream>
#include "budget.hpp"
#include <string>
#include <fstream>

/////////////////////////////////////////BUDGET CLASS

Budget::Budget(){
        name = "NULL";
        allowance = 0;
		amtSpent = 0;
}

Budget::Budget(std::string userName, int userAllowance){
        name = userName;
        allowance = userAllowance;
}

std::string Budget::getName(){
        return name;
}

int Budget::getAllowance(){
        return allowance;
}

int Budget::getAmtSpent() {
	return amtSpent;
}

void Budget::editBudgetValues(std::string userName, int userAllowance){
        name = userName;
        allowance = userAllowance;
}

void Budget::displayPurchases(){
        for(int i = 0; i < purchases.size(); i++){
                std::cout<<"----------------------------------------------------"<<std::endl;
                std::cout<<"Purchase Name: "<<purchases[i].getName()<<std::endl;
                std::cout<<"Purchase Date: "<<purchases[i].getDate()<<std::endl;
                std::cout<<"Purchase Amount: "<<purchases[i].getAmount()<<std::endl;
        }
}

void Budget::addPurchaseEntry(std::string purName, int purDate, int purAmt){
        Purchase myPurch(purName, purDate, purAmt);
        purchases.push_back(myPurch);
		amtSpent += purAmt;
}

int Budget::computeRemainingAllowance(int amtSpent, int allowance) {
	return allowance - amtSpent;
}

///////////////////////////////////////PURCHASE CLASS

Purchase::Purchase(){
        name = "NULL";
        date = 0;
        amount = 0;
}

Purchase::Purchase(std::string userName, int userDate, int userAmount){
        name = userName;
        date = userDate;
        amount = userAmount;
}

std::string Purchase::getName(){
        return name;
}

int Purchase::getDate(){
        return date;
}

int Purchase::getAmount(){
        return amount;
}

//////////////////////////////////////////ROGUE FUNCTIONS
int stringToInt(std::string str){
        std::vector<int> intVec;
        char ch;
        int result = 0;
        int holder = 0;
        for(int i = 0; i < str.size(); i++){
                ch = str[i];
                if(ch != '\0'){
                        holder = ch - '0';
                        intVec.push_back(holder);
                }
        }
        for(int i = 0; i < intVec.size(); i++){
                holder = intVec[i];
                result = (result * 10) + holder;
        }
        return result;
}

void displayBudgets(std::vector<Budget> listOfBudgets, int budgetItr) {
	std::cout << "Budget: " << listOfBudgets[budgetItr].getName() << std::endl;
	std::cout << "Starting Allowance: " << listOfBudgets[budgetItr].getAllowance() << std::endl;
	std::cout << "Remaining Allowance: " << listOfBudgets[budgetItr].computeRemainingAllowance(listOfBudgets[budgetItr].getAllowance(), listOfBudgets[budgetItr].getAmtSpent()) << std::endl;
}

void saveBudgets(std::vector<Budget> budgets, const char *saveLocation) {
	std::ofstream myFile;

	remove(saveLocation);
	myFile.open(saveLocation);

	if (myFile.is_open()) {
		myFile << "***" << std::endl;
		for (int i = 0; i < budgets.size(); i++) {
			for (int j = 0; j < budgets[i].purchases.size(); j++) {
				myFile << budgets[i].purchases[j].getName() << std::endl;
				myFile << budgets[i].purchases[j].getDate() << std::endl;
				myFile << budgets[i].purchases[j].getAmount() << std::endl;
			}
			myFile << budgets[i].getName() << std::endl;
			myFile << budgets[i].getAllowance() << std::endl;
			myFile << "-.-.-.-" << std::endl;
		}
		myFile.close();
		std::cout << "Budgets Saved Successfully!" << std::endl;
	}
	else {
		std::cout << std::endl << "**Could not open save file**" << std::endl << std::endl;
	}
}

void loadBudgets(std::vector<Budget> & budgets, const char *loadLocation) {
	std::ifstream myFile;
	std::vector<std::string> lines;
	std::string myString;

	myFile.open(loadLocation);

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, myString);
			lines.push_back(myString);
		}
		for (int i = 0; i < lines.size(); i++) {
			if (lines[i] == "-.-.-.-") {
				Budget myBudget(lines[i - 2], stringToInt(lines[i - 1]));
				int j = i - 3;
				while ((lines[j] != "-.-.-.-") && (lines[j] != "***")) {
					myBudget.addPurchaseEntry(lines[j - 2], stringToInt(lines[j - 1]), stringToInt(lines[j]));
					j -= 3;
				}
				budgets.push_back(myBudget);
			}
		}
	}
	else {
		std::cout << "Could not load budgets." << std::endl;
	}
}

void deleteBudgets(std::vector<Budget> & budgets, const char *saveLocation) {
	for (int i = 0; i < budgets.size(); i++) {
		budgets.pop_back();
	}
	remove(saveLocation);
}