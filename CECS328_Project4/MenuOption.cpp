// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4


#include "MenuOption.hpp"

MenuOption::MenuOption(string desc, void (*op)())    {
    description = desc;
    operation = op;
}

string MenuOption::get_decription() {   return description; }

void MenuOption::runOperation()     {   (*operation)();     }
