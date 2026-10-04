#include <iostream>
#include <thread>
using namespace std;

//New function countUp runs through a for loop counting from 0 to 20. 
// Prints i each time it increases.
void countUp(){
    for (int i = 0; i<=20; i++){
        cout << i << endl;
    }
    //informs user when the count up is complete.
    cout << "Completed Count Up." << endl << endl;
}

//New function countDown runs through a for loop counting from 20 to 0.
//Prints i each time it decreases.
void countDown(){
    for(int i = 20; i >=0; i--){
        cout << i << endl;
    }
    //Informs user when the count down is complete.
    cout << "Completed Count Down." << endl << endl;
}

int main(){
    //thread1 created and countUp function called for thread1
    thread thread1(countUp);
    //Forces thread2 to action until thread1 is joined to main per the instructions in the assignment prompt.
    thread1.join();

    //thread2 is created and countDown function called for thread2
    thread thread2(countDown);
    //thread2 is joined to main.
    thread2.join();

    return 0;
}