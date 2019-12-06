// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#include "Implementations.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Step1()    {

}

void Step2()    {

}

void Step3()    {

}

void Step4()    {

}

void Quit() {
    
}
/*
int* radix_sort(int* arr, int size_of_arr)  {

}
int* quicksort(int* arr, int p, int r)  {

}
int partition(int* arr, int p, int r)   {

}
 */

void print_array(int* arr, int size_of_arr) {
    for (int i = 0; i < size_of_arr; i++)   {
        cout << *(arr+i);
    }
    
    cout << endl;
}

void get_array_of_ints_from_string(string comma_sep_string, int* &values, int &sizeofarr, bool is_delimeter)   {
    
    // I need to use a string stream to get the data out of the string directly,
    // Since I don't know its exact size.
    stringstream stream_of_raw_text(comma_sep_string);
    
    // If the array is comma-delimited, then we need to find the size.
    if (is_delimeter)   {
        // First, I find the number of commas. I did this because if there
        // is n commas, then there are n+1 numbers.
        sizeofarr = 1;
        for(char i; stream_of_raw_text >> i;) {
            if(i == ',')    {
                sizeofarr++;
            }
        }
    }
    
    // Now, I need to put all of the integers into an array
    values = new int[sizeofarr];
    
    // After I have the array, I know that I can have a new string where it adds
    // every integer to a string, and then knows that it needs to terminate once
    // it hits a comma.
    
    stringstream second_stream_of_raw_text(comma_sep_string);
    for(int i = 0; i < sizeofarr; i++)   {
        // current_number_as_a_string is a string that adds all the characters
        // that need to be in the next number. For example, if the next number
        // in the array is 123, then current_number_as_a_string will be "", then
        // "1" after the first pass of the loop, then "12" after the second pass,
        // then "123" after the third pass. Once it is in this state, then we can
        // convert it into an int.
        
        // I was having trouble getting the loop to detect the charcter '\0'. However,
        // the terminating character for a string stream is saved as -1, so I was able
        // to simply use that
        
        // If there is no delimiter, then we simply need to read in each character as
        // its exact value
        
        string current_number_as_a_string = "";
        if (is_delimeter)   {
            
            while (second_stream_of_raw_text.peek() != ',' && second_stream_of_raw_text.peek() != -1) {
                char tempchar;
                second_stream_of_raw_text >> tempchar;
                current_number_as_a_string.append(1,tempchar);
            }
            // If the while loop ended, and the next character is ',' then we still
            // want to run the code
            if (second_stream_of_raw_text.peek() == ',')    {
                char throwaway;
                second_stream_of_raw_text >> throwaway;
            }
        }
        else    {
            // If there are characters left, save their value
            if (second_stream_of_raw_text.peek() != -1) {
                char tempchar;
                second_stream_of_raw_text >> tempchar;
                current_number_as_a_string.append(1,tempchar);
            }
            // If there are no characters left, then save 0.
            else    {
                current_number_as_a_string.append(1,'0');
            }
        }
        
        // Here, we convert current_number_as_a_string into an int, and add it to
        // the array.
        values[i] = stoi(current_number_as_a_string);
    }
    
    
}



void get_random_array(int* &rand_array, int size_of_rand_array, int M) {
    // Makes the array
    rand_array = new int[size_of_rand_array];
    
    // Populates the array
    for (int i = 0; i < size_of_rand_array; i++)    {
        // Creates a random value between 0 and 2147483647, and takes the modulus
        // of that and 101 to get a number between 0 and 2000. Then, I subtract the answer
        // by 1000, so that all numbers in the range are between -1000 and 1000
        rand_array[i] = (rand() % (M + 1));
    }
}



int* copyArray(int* arrayToBeCopied, int sizeOfArray)   {
    int* newArray = new int[sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++)   {
        newArray[i] = arrayToBeCopied[i];
    }
    return newArray;
}
