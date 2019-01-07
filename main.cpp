/*
		*Ian Whitesel
		*Budget Application Main
		*01/04/2019

		TODO: Cannot enter multi-word phrases | Finish adding prompts for removing budgets | Fix the math of adding and subtracting purchases | Set up DATE correctly
*/

#include <iostream>
#include "budget.hpp"
#include <string>
#include <vector>
#include <Windows.h>
#include <direct.h>

const char *dirPath = "C:/Budget_Application";
const char *filePath = "C:/Budget_Application/save.txt";
char userChoice = '*';

int main(){
		//Create Directory for saving
		if (directoryExists(dirPath)) {
			std::cerr << "Directory exists" << std::endl;
		}
		else {
			std::cerr << "Directory does not exist" << std::endl;
			_mkdir(dirPath);
		}

		std::vector<Budget> budgets;
		loadBudgets(budgets, filePath);

		std::cout << "Welcome to Ian's Budget Application." << std::endl;

        while((userChoice != 'Q') && (userChoice != 'q')){
                std::cout<<"[C]Create Budget | [P]Log Purchase | [S]See Budgets | [X]Delete Data | [Q]Quit"<<std::endl;
                std::cin>>userChoice;

                if((userChoice == 'C') || (userChoice == 'c')){

                        std::string budgetName = "";
                        int budgetAllowance = 0;

                        std::cout<<"Enter Name of Budget: ";
                        std::cin>>budgetName;
                        std::cout<<"Enter Budget Allowance: ";
                        std::cin>>budgetAllowance;

                        Budget userBudget(budgetName, budgetAllowance);
                        budgets.push_back(userBudget);

                } else if ((userChoice == 'P') || (userChoice == 'p')) {

                        std::string purBudget = "";
                        std::string purName = "";
                        int purDate = 0;
                        int purAmt = 0;

                        std::cout<<"Enter Budget to add Purchase to: ";
                        std::cin>>purBudget;
                        std::cout<<"Enter Name of Purchase: ";
                        std::cin>>purName;
                        std::cout<<"Enter Date of Purchase: ";
                        std::cin>>purDate;
                        std::cout<<"Enter Amount spent: ";
                        std::cin>>purAmt;

                        for(int i = 0; i < budgets.size(); i++){
                                if(purBudget == budgets[i].getName()){
                                        budgets[i].addPurchaseEntry(purName, purDate, purAmt);
                                }
                        }

				}
				else if ((userChoice == 'S') || (userChoice == 's')) {
					char subUserChoice = '*';
					while ((subUserChoice != 'Q') && (subUserChoice != 'q')) {

						std::cout << "Here are your budgets: " << std::endl;
						for (int i = 0; i < budgets.size(); i++) {
							std::cout << "----------------------------------------------------" << std::endl;
							std::cout << "Name: " << budgets[i].getName() << std::endl;
							std::cout << "Allowance Remaining: " << budgets[i].getAllowance() << std::endl;
							std::cout << "Purchases:" << std::endl;
							budgets[i].displayPurchases();
						}

						std::cout << "What would you like to do with them? [B]Delete Budget | [P]Delete Purchase | [Q]Main Menu" << std::endl;
						std::cin >> subUserChoice;

						if ((subUserChoice == 'B') || (subUserChoice == 'b')) {
							std::cout << "Are you sure you want to delete a budget? [Y]Yes | [N]No" << std::endl;
							char deleteChoice = '*';
							std::cin >> deleteChoice;
							if ((deleteChoice == 'Y') || (deleteChoice == 'y')) {
								std::cout << "Enter the name of the budget you want to delete: ";
								std::string budgetToDelete = "";
								std::cin >> budgetToDelete;
								removeBudget(budgets, budgetToDelete);
								std::cout << "Budget " << budgetToDelete << " has been removed." << std::endl;
							}
						}
						else if ((subUserChoice == 'P') || (subUserChoice == 'p')) {
							std::cout << "Are you sure you want to delete a purchase? [Y]Yes | [N]No" << std::endl;
							char deleteChoice = '*';
							std::cin >> deleteChoice;
							if ((deleteChoice == 'Y') || (deleteChoice == 'y')) {
								std::cout << "Enter the name of the budget the purchase belongs to: ";
								std::string budgetToDelete = "";
								std::cin >> budgetToDelete;
								std::cout << "Enter the name of the purchase you want to delete: ";
								std::string purchaseToDelete = "";
								std::cin >> purchaseToDelete;
								removePurchase(budgets, budgetToDelete, purchaseToDelete);
								std::cout << "Purchase " << purchaseToDelete << " has been removed." << std::endl;
							}
						}
					}
				}

				else if ((userChoice == 'X') || (userChoice == 'x')) {

					char deleteChoice = '*';
					while ((deleteChoice != 'N') && (deleteChoice != 'Y') && (deleteChoice != 'n') && (deleteChoice != 'y')) {
						std::cout << std::endl << "**WARNING**" << std::endl << std::endl;
						std::cout << "This will DELETE all of your data" << std::endl << "Proceed? [Y]Yes | [N]No" << std::endl;
						std::cin >> deleteChoice;
						if ((deleteChoice == 'Y') || (deleteChoice == 'y' )){
							deleteBudgets(budgets, filePath);
							std::cout << "Data Deleted." << std::endl;
						}
					}
				}

				else if ((userChoice == 'Q') || (userChoice == 'q')) {

					saveBudgets(budgets, filePath);
				}
        }
}
