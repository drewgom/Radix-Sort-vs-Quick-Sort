// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#ifndef Implementations_hpp
#define Implementations_hpp

#include <string>

using namespace std;

void Step1();
void Step2();
void Step3();
void Step4();
void Quit();
int* radix_sort(int* arr, int size_of_arr);
int* quicksort(int* arr, int p, int r);
int partition(int* arr, int p, int r);
void print_array(int* arr, int size_of_arr);
void get_array_of_ints_from_string(string comma_sep_string, int* &values, int &sizeofarr, bool is_delimeter);
void get_random_array(int* &rand_array, int size_of_rand_array, int M);
int* copyArray(int* arrayToBeCopied, int sizeOfArray);

#endif
