#include <iostream>
#include <limits>

using namespace std;
//Function to get a valid input for an integer. cin does not throw an exception but consistently fails, so we use the while loop to check and prompt for a correct input and return input.
int getValidInteger(){
    int input;
    while(!(cin >> input)){
        cout << "Invalid input, please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}
//Function to manage assigning a pointer to a new int value and print out the original value, value at the pointer and the pointer address. 

void printInfo(int value, int* &pointer){
    pointer = new int(value);
    cout << "Original value: " << value << endl;
    cout << "Pointer value: " << *pointer << endl;
    cout << "Pointer address: " << pointer << endl;
    cout << endl;
}

int main() {
    //Variables
    int value1;
    int value2;
    int value3;
    int* pointer1;
    int* pointer2;
    int* pointer3;

    //Instructions for user.
    cout << "Please provide three integer values." << endl;
    cout << "Enter your first value: ";

    //Function to get a valid integer for value1, value2, and value3.
    value1 = getValidInteger();
    cout << endl;

    cout << "Enter your second value: ";
    value2 = getValidInteger();
    cout << endl;

    cout << "Enter your third value: ";
    value3 = getValidInteger();
    cout << endl;
    //Calling function print info to print all info for each value and pointer.
    printInfo(value1, pointer1);
    printInfo(value2, pointer2);
    printInfo(value3, pointer3);

    //Block to delete and set pointers to nullptr. (I could include it in the printInfo Function but I wanted to see the different memory addresses).
    delete pointer1;
    delete pointer2;
    delete pointer3;
    pointer1 = nullptr;
    pointer2 = nullptr;
    pointer3 = nullptr;

    return 0;

}