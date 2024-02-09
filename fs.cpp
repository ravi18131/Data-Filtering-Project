#include <iostream>
#include <fstream>

using namespace std;  // Add this line to use the std namespace

void deleteNonAlphabeticChars(const string &inputFilePath, const string &outputFilePath) {
    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if (inputFile.is_open() && outputFile.is_open()) {
        int currentChar;
        while ((currentChar = inputFile.get()) != EOF) {
            if ((65 <= currentChar && currentChar <= 90) || (97 <= currentChar && currentChar <= 122) ||
                (currentChar == 32) || (currentChar == 44) || (46 <= currentChar && currentChar <= 59) || (currentChar == 10)) {
                char currentCharAsChar = static_cast<char>(currentChar);
                outputFile.put(currentCharAsChar);
            }
        }

        inputFile.close();
        outputFile.close();
    } else {
        cerr << "Error opening files." << endl;
    }
}

int main() {
    string inputFilePath = "input.txt";
    string outputFilePath = "output.txt";
    deleteNonAlphabeticChars(inputFilePath, outputFilePath);

    return 0;
}
