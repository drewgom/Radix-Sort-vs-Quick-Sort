// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#include "Implementations.hpp"
#include "Timer.hpp"
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
    int n;
    int M;
    int* arr;
    Timer sort_timer;
    
    // gets the information to create the values
    cout << "Please enter in the size of the array you would like: " << endl;
    cin >> n;
    cout << "Please enter in the maximum values for the array you would like: " << endl;
    cin >> M;
    cin.ignore();
    arr = new int[n];
    get_random_array(arr, n, M);
    
    if (n < 100)    {
        cout << "Array before sort: " << endl;
        print_array(arr, n);
        
    }
    // Sorts the array
    cout << "Sorting array using quicksort. . ." << endl;
    sort_timer.start_timer();
    quicksort(arr, 0, n-1);
    sort_timer.stop_timer();
    double quicksort_time = sort_timer.get_time();
    
    // Prints the results
    if (quicksort_time <= 1000000000)  {
        cout << "Elapsed time for quicksort: " << quicksort_time/1000000 << "ms" << endl;
    }
    else {
        cout << "Elapsed time for quicksort: " << quicksort_time/1000000000 << "sec" << endl;
    }
    if(n < 100) {
        cout << "Here is the sorted array:" << endl;
        print_array(arr, n);
    }
    
    
    
    
    
    
}

void Quit() {
    exit(0);
}

/*
void radix_sort(int* arr, int size_of_arr)  {

}
 */

void counting_sort(int* arr, int* second_array, int size_of_arr, int largest_possible_value)   {
    int* amount_of_each_number = new int[largest_possible_value+1];
    
    for (int i = 0; i < largest_possible_value+1; i++)    {
        amount_of_each_number[i] = 0;
    }
    
    for (int i = 0; i < size_of_arr; i++)    {
        amount_of_each_number[arr[i]] += 1;
    }
    
    for (int i = 1; i < largest_possible_value+1; i++)       {
        amount_of_each_number[i] = amount_of_each_number[i] + amount_of_each_number[i-1];
    }
    
    for (int i = size_of_arr-1; i >= 0; i--)    {
        // TODO: try as second_array[amount_of_each_number[arr[i]]]
        second_array[amount_of_each_number[arr[i]]-1] = arr[i];
        amount_of_each_number[arr[i]] -= 1;
    }
    
}

void quicksort(int* arr, int p, int r)  {
    if(p < r)   {
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

int partition(int* arr, int p, int r)   {
    int x = arr[r];
    
    int i = p - 1;
    
    for (int j = p; j < r; j++)   {
        if (arr[j] <= x)    {
            i = i+1;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);
    

    return i+1;
}
 

void print_array(int* arr, int size_of_arr) {
    for (int i = 0; i < size_of_arr; i++)   {
        cout << arr[i];
        if (i != size_of_arr-1) {
            cout << ", ";
        }
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




void swap(int* arr, int i, int j)   {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
