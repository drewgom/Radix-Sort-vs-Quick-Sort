// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#include "Menu.hpp"
#include <iostream>
#include <iomanip>


// This is the constructor for the menu
Menu::Menu (int projnum, string desc, string instr, int numofops, MenuOption *arrofops) {
    project_number = projnum;
    description = desc;
    instructions = instr;
    number_of_menu_options = numofops;
    array_of_options = arrofops;
}

void Menu::display_menu()    {
    cout << "-----------------------------PROJECT " << project_number << "-----------------------------" << endl;
    cout << description << endl;
    
    int choice;
    // This will continue to prompt a user and run their command until they quit
    while(true)  {
        cout << instructions << endl;
        for (int i = 0; i <  number_of_menu_options; i++)   {
            cout << left << i+1 << ") " << array_of_options[i].get_decription() << endl;
        }
        cin >> choice;
        cin.ignore();
        
        // Runs the operation
        array_of_options[choice-1].runOperation();
        cout << endl;
    }
}
