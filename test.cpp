/*
		*Ian Whitesel
		*Budget Application Test File
		*01/04/2019
*/

#include <iostream>
#include "budget.hpp"
#include <string>
#include <cassert>
#include <fstream>
/*
const char *path = "C:/Users/Ian/Documents/file.txt";

int main() {
	{
		//setup BUDGET DEFAULT CTOR
		Budget myBudget;
		//initialize

		//verify
		assert(myBudget.getName() == "NULL");
		assert(myBudget.getAllowance() == 0);

		std::cout << "Budget Name: " << myBudget.getName() << std::endl;
		std::cout << "Budget Allowance: " << myBudget.getAllowance() << std::endl;

		std::cout << "Budget default ctor passed!" << std::endl;
	}
	{
		//setup BUDGET CREATION CTOR
		Budget myBudget("Entertainment", 50);
		//initialize

		//verify
		assert(myBudget.getName() == "Entertainment");
		assert(myBudget.getAllowance() == 50);

		std::cout << "Budget Name: " << myBudget.getName() << std::endl;
		std::cout << "Budget Allowance: " << myBudget.getAllowance() << std::endl;

		std::cout << "Budget creation ctor passed!" << std::endl;
	}
	{
		//setup PURCHASE DEFAULT CTOR
		Purchase myPurchase;
		//initialize

		//verify
		assert(myPurchase.getName() == "NULL");
		assert(myPurchase.getDate() == 0);
		assert(myPurchase.getAmount() == 0);

		std::cout << "Purchase Name: " << myPurchase.getName() << std::endl;
		std::cout << "Purchase Date: " << myPurchase.getDate() << std::endl;
		std::cout << "Purchase Amount: " << myPurchase.getAmount() << std::endl;

		std::cout << "Purchase default ctor passed!" << std::endl;
	}
	{
		//setup PURCHASE CREATION CTOR
		Purchase myPurchase("Oil Change", 2019, 50);
		//initialize

		//verify
		assert(myPurchase.getName() == "Oil Change");
		assert(myPurchase.getDate() == 2019);
		assert(myPurchase.getAmount() == 50);

		std::cout << "Purchase Name: " << myPurchase.getName() << std::endl;
		std::cout << "Purchase Date: " << myPurchase.getDate() << std::endl;
		std::cout << "Purchase Amount: " << myPurchase.getAmount() << std::endl;

		std::cout << "Purchase creation ctor passed!" << std::endl;
	}
	{
		//setup BUDGET ADD PURCHASE ENTRY
		Budget myBudget("Car", 100);
		//initialize
		std::cout << "Budget Allowance before oil change: " << myBudget.getAllowance() << std::endl;

		myBudget.addPurchaseEntry("Harrison Ford Oil Change", 2019, 50);
		//verify
		assert(myBudget.getAllowance() == 100 - 50);

		std::cout << "Budget Allowance after oil change: " << myBudget.getAllowance() << std::endl;

		std::cout << "Budget::addPurchaseEntry passed!" << std::endl;
	}
	{
		//setup BUDGET DISPLAYPURCHASE 1 purchase
		Budget myBudget("Food", 100);
		//initialize
		myBudget.addPurchaseEntry("Churro", 2019, 2);
		//verify
		assert(myBudget.purchases.size() == 1);
		std::cout << "Purchases: " << std::endl;
		myBudget.displayPurchases();
	}
	{
		//setup BUDGET DISPLAYPURCHASE multi purchase
		Budget myBudget("Food", 100);
		//initialize
		myBudget.addPurchaseEntry("Churro", 2019, 2);
		myBudget.addPurchaseEntry("Ice Cream", 2019, 4);
		myBudget.addPurchaseEntry("Cookie", 2019, 6);
		myBudget.addPurchaseEntry("Salsa", 2019, 8);
		//verify
		assert(myBudget.purchases.size() == 4);
		std::cout << "Purchases: " << std::endl;
		myBudget.displayPurchases();
	}
	{
		//setup intToString
		std::string str = "150";
		//ini
		int result = stringToInt(str);
		//verify
		assert(result == 150);
	}
	{
		//setup intToString
		std::string str = "1";
		//ini
		int result = stringToInt(str);
		//verify
		assert(result == 1);
	}
	{
		//setup intToString
		std::string str = "0";
		//ini
		int result = stringToInt(str);
		//verify
		assert(result == 0);
	}
	{
		//setup intToString
		std::string str = "9999";
		//ini
		int result = stringToInt(str);
		//verify
		assert(result == 9999);
	}
	
	{
		//setup ROGUE WRITING TO FILE
		std::ofstream myFile;
		Budget myGasBudget("Gas", 500);
		myGasBudget.addPurchaseEntry("Gas", 2019, 2);
		myGasBudget.addPurchaseEntry("Gas", 2019, 40);
		myGasBudget.addPurchaseEntry("Oil Change", 2019, 6);
		myGasBudget.addPurchaseEntry("Harrison Ford Oil Change", 2019, 90);
		Budget myFoodBudget("FOOD", 100);
		myFoodBudget.addPurchaseEntry("Churro", 2019, 2);
		myFoodBudget.addPurchaseEntry("Ice Cream", 2019, 4);
		myFoodBudget.addPurchaseEntry("Cookie", 2019, 6);
		myFoodBudget.addPurchaseEntry("Salsa", 2019, 8);
		std::vector<Budget> budgets;
		budgets.push_back(myFoodBudget);
		budgets.push_back(myGasBudget);
		//initialize    //Can turn this into a function "save"?
		remove(path);
		myFile.open(path);
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
		}
		//verify
	}
	
	{
		//setup ROGUE READING FROM FILE
		std::vector<Budget> budgets;

		std::cout << std::endl << "READ FROM FILE: " << std::endl << std::endl;

		std::ifstream myFile;
		std::vector<std::string> lines;
		std::string myString;
		int counter = 0;
		//ini
		myFile.open(path);
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
					counter++;
				}
			}
			std::cout << "Number of Budgets: " << counter << std::endl;
		}
		//verify
		for (int i = 0; i < budgets.size(); i++) {
			std::cout << "*****************************************" << std::endl;
			displayBudgets(budgets, i);
			budgets[i].displayPurchases();
		}
	}
	{
	//setup SAVE FUNC
		Budget myGasBudget("Gas", 500);
		myGasBudget.addPurchaseEntry("Gas", 2019, 2);
		myGasBudget.addPurchaseEntry("Gas", 2019, 40);
		myGasBudget.addPurchaseEntry("Oil Change", 2019, 6);
		myGasBudget.addPurchaseEntry("Harrison Ford Oil Change", 2019, 90);
		Budget myFoodBudget("FOOD", 100);
		myFoodBudget.addPurchaseEntry("Churro", 2019, 2);
		myFoodBudget.addPurchaseEntry("Ice Cream", 2019, 4);
		myFoodBudget.addPurchaseEntry("Cookie", 2019, 6);
		myFoodBudget.addPurchaseEntry("Salsa", 2019, 8);
		std::vector<Budget> budgets;
		budgets.push_back(myFoodBudget);
		budgets.push_back(myGasBudget);
	//ini
		saveBudgets(budgets, path);
	//verify
	}
	{
		//setup LOAD FUNC
		std::vector<Budget> budgets;
		//ini
		loadBudgets(budgets, path);
		//verify
		std::cout << std::endl << "FROM LOAD FUNC TEST: " << std::endl << std::endl;
		for (int i = 0; i < budgets.size(); i++) {
			std::cout << "*****************************************" << std::endl;
			displayBudgets(budgets, i);
			budgets[i].displayPurchases();
		}
	}
	char end;
	std::cin >> end;
}
*/
