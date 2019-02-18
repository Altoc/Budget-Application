/*
        *Ian Whitesel
        *Budget Application Header
        *01/04/2019
*/

#ifndef BUDGET_HPP
#define BUDGET_HPP

#include <iostream>
#include <string>
#include <vector>
//#include <Windows.h>

class Purchase{
public:
        Purchase();                                                     //default ctor
        Purchase(std::string userName, int userDate, int userAmount);   //ctor for creation of purchase

        std::string getName();
        int getDate();
        int getAmount();
private:
        std::string name;                                                                                               //Name of purchase
        int date;                                                                                                               //Date of purchase
        int amount;                                                                                                             //Amount spent in the purcha$
};

class Budget{
public:
        Budget();                                                                                                                               //default ct$
        Budget(std::string userName, int userAllowance);                                                //ctor for creation of budget

        std::string getName();
        int getAllowance();
        int getAmtSpent();
        void editBudgetValues(std::string userName, int userAllowance);                 //changes name and allowance
        void displayPurchases();                                                                                                //Couts purchases
        void addPurchaseEntry(std::string purName, int purDate, int purAmt, bool iniPurchaseEntry);     //Add Purchase to Budget
        void subtractRemainingAllowance(int amtSpent);                  //Returns budget remainder
        void addRemainingAllowance(int amtGained);                                      //Returns budget remainder

        std::vector<Purchase> purchases;                                                                                //purchases made
private:
        std::string name;                                                                                                               //Name of the budget
        int allowance;                                                                                                                  //Amt allowed to the$
        int amtSpent;                                                                                                                   //Amt spent via purc$
};

int stringToInt(std::string);

void displayBudgets(std::vector<Budget> listOfBudgets, int budgetItr);
void saveBudgets(std::vector<Budget> budgets, const char *saveLocation);
void loadBudgets(std::vector<Budget> & budgets, const char *loadLocation);
void deleteBudgets(std::vector<Budget> & budgets, const char *saveLocation);
int searchBudget(std::vector<Budget> & budgets, std::string budgetName);
void removeBudget(std::vector<Budget> & budgets, std::string budgetName);

int searchPurchase(std::vector<Budget> & budgets, std::string budgetName, std::string purchaseName);
void removePurchase(std::vector<Budget> & budgets, std::string budgetName, std::string purchaseName);

bool directoryExists(const char* dirName);      //checks if directory exists

#endif //BUDGET_HPP


