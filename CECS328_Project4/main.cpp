// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#include <iostream>
#include "Implementations.hpp"
#include "MenuOption.hpp"
#include "Menu.hpp"

using namespace std;

int main() {
    string proj_4_description = "BINARY, RADIX SORT, AND QUICKSORT";
    string proj_4_intruction = "Please enter the number of your desired menu option:";
    
    // The descriptions of each menu
    
    
    string step_1_description = "Display your heap";
    string step_2_description = "Create an empty min heap";
    string step_3_description = "Creates a min heap using user entered data";
    string step_4_description = "Generate a random heap";
    string quit_description = "Quits the program";
    
    MenuOption op1(step_1_description, &Step1);
    MenuOption op2(step_2_description, &Step2);
    MenuOption op3(step_3_description, &Step3);
    MenuOption op4(step_4_description, &Step4);
    MenuOption op5(quit_description, &Quit);

    
    // Creates a list of all the menu options
    MenuOption listOfOptions[] = {op1, op2, op3, op4, op5};
    // Makes a new table object
    Menu Project4Menu(4, proj_4_description, proj_4_intruction, 5, listOfOptions);
    Project4Menu.display_menu();
    
    
    return 0;
}
