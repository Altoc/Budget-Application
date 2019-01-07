/*
		*Ian Whitesel
		*Budget Application Main
		*01/04/2019

		TODO: Delete function does not work | Cannot enter multi-word phrases
*/

#include <iostream>
#include "budget.hpp"
#include <string>
#include <vector>

const char *path = "C:/Users/Ian/Documents/file.txt";
char userChoice = '*';

int main(){
        std::vector<Budget> budgets;
		
		loadBudgets(budgets, path);

		std::cout << "Welcome to Ian's Budget Application." << std::endl;

        while(userChoice != 'Q'){
                std::cout<<"[C]Create Budget | [P]Log Purchase | [S]See Budgets | [D]Delete Data | [Q]Quit"<<std::endl;
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

                } else if ((userChoice == 'S') || (userChoice == 's')) {

                        std::cout<<"Here are your budgets: "<<std::endl;

                        for(int i = 0; i < budgets.size(); i++){
								std::cout << "----------------------------------------------------" << std::endl;
                                std::cout<<"Name: "<<budgets[i].getName()<<std::endl;
                                std::cout<<"Allowance Remaining: "<<budgets[i].getAllowance()<<std::endl;
                                std::cout<<"Purchases:"<<std::endl;
                                budgets[i].displayPurchases();
                        }

				}
				else if ((userChoice == 'D') || (userChoice == 'd')) {
					char deleteChoice = '*';
					while ((deleteChoice != 'N') && (deleteChoice != 'Y') && (deleteChoice != 'n') && (deleteChoice != 'y')) {
						std::cout << std::endl << "**WARNING**" << std::endl << std::endl;
						std::cout << "This will DELETE all of your data" << std::endl << "Proceed? [Y]Yes | [N]No" << std::endl;
						std::cin >> deleteChoice;
						if ((deleteChoice == 'Y') || (deleteChoice == 'y' )){
							deleteBudgets(budgets, path);
							std::cout << "Data Deleted." << std::endl;
						}
					}
				}
				else if ((userChoice == 'Q') || (userChoice == 'q')) {
					saveBudgets(budgets, path);
				}
        }
}
