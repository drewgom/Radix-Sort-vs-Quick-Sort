// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#ifndef Menu_hpp
#define Menu_hpp

#include "MenuOption.hpp"
#include <string>

using namespace std;


class Menu  {
private:
    int project_number;
    string description;
    string instructions;
    int number_of_menu_options;
    MenuOption *array_of_options;
public:
    Menu(int projnum, string desc, string instr, int numofops, MenuOption *arrofops);
    void display_menu();
};



#endif
