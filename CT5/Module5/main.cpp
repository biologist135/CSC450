#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Reverses the contents of the input file and writes
// the reversed characters to a second file.
void reverseFile(string inputFileName, string reverseFileName) {

    //Reads the inputFile
    ifstream inputFile(inputFileName);
    //Checks to make sure the inputFile is open
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file." << endl;
        return;
    }

    //Input stream buffer iterates over the characters found in the inputFile and stores in the fileContents variable.
    string fileContents(
        (istreambuf_iterator<char>(inputFile)),
        istreambuf_iterator<char>()
    );
    //Close the file.
    inputFile.close();

    //From Algorithm, reverses all information found in fileContents variable from start to end of the string.
    reverse(fileContents.begin(), fileContents.end());

    //Opens reverseFile to write information to the file.
    ofstream reverseFile(reverseFileName);

    //Check if the reverse file is open.
    if (!reverseFile.is_open()) {
        cout << "Error: Unable to create reverse file." << endl;
        return;
    }

    //Inputs fileContents which is now reversed into reverseFile, and closes the reverseFile.
    reverseFile << fileContents;
    reverseFile.close();
}


int main() {
    //Saving file names to variables for simplified calling.
    string inputFileName = "CSC450_CT5_mod5.txt";
    string reverseFileName = "CSC450-mod5-reverse.txt";
    string userInput;

    //Providing instruction to user.
    cout << "Enter text to append to the file: ";

    //Called getline to capture userInput for the entire typed string.
    getline(cin, userInput);

    //Output file stream takes the input file name and uses append mode to add information to the end of the file.
    ofstream inputFile(inputFileName, ios::app);

    //Check to see that the file opened correctly. Communicates if there is an issue with opening the file.
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }
    //Appends userInput into the input file, and closes the file.
    inputFile << userInput << endl;
    inputFile.close();

    //Calls the revers function above which reads the input file and writes to the reverse file.
    reverseFile(inputFileName, reverseFileName);

    //Provides information indicating what was done with the input.
    cout << "Text successfully added to " << inputFileName << endl;
    cout << "Reversed file successfully created as "
         << reverseFileName << endl;

    return 0;
}