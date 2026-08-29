#include <iostream>

//calling the standard library for C++
using namespace std;

//built a struct to organize the string pair and the concatenate method.
struct stringPair {
		std::string str1;
		std::string str2;

		//Created a concatenate method for the struct to automatically combine str1, and str2 with a space in between.
		void concatenate(){
			std::string str3 = str1 + " " + str2;

			cout << "Your output is: "<< str3 << endl;
		}

		//created a checkEmpty method within the stringPair struct to confirm that the variable has at least one character.
		void checkEmpty(std::string& string){

			while(string.empty()){
				cout << "You must enter a word or phrase: ";
				std::getline(cin, string);
			}
		}
	};


//Main method
int main()

{
	//Providing user instruction for the program
	cout << "You will be providing two words/phrases which will be combined and printed. You will do this 3 times." << endl;
	//Established a count int variable to keep track of the number of times we perform the concatenation.
	int count = 1;
	//implemented the string pair struct as sample.
	stringPair sample;

	//to account for the requirement for 3 outputs, we implemented a while loop
	while(count <= 3){

		//Instruction to useer to type first word or phrase.
		cout << "Please input your first word/phrase of the pair: ";

		/*Used the getline() member function to accommodate words and phrases in a string. This is different than
		 * just using cin which has a delimiter of spaces and would only take the first word typed.
		 */
		std::getline(cin, sample.str1);

		//calling a method to check if the string is empty.
		sample.checkEmpty(sample.str1);

		//Instruction to user to type the second word or phrase.
		cout << "Please input your second word/phrase of the pair: ";

		//std::getline() as a means of getting full user input.
		std::getline(cin, sample.str2);

		//Calling a method to check if the second string is empty.
		sample.checkEmpty(sample.str2);

		//Calling the concatenate method within the struct for string pair.
		sample.concatenate();

		//Message letting the user know how many times they have submitted a word or phrase.
		cout << "You have submitted " << count << "/3 pairs of words or phrases." << endl;
		cout << endl;

		//updating the count variable to move towards the while loop argument to prevent an infinite loop.
		count++;

	}
	cout << "Program complete.";

}
