#include <iostream>
#include <fstream>
using namespace std;

void writeUserInputToFile(string &fileName) {
  fstream myFile(fileName, ios::app);
  
  if(myFile.is_open()) {
    cout << "Enter content to add to file" << endl;
    string userInput;
    getline(cin, userInput);
    myFile << userInput << endl;
    myFile.close();
  }
}

void reverseFileContents(string &fileName, string &outputFileName) {
  ifstream myFile(fileName);

  if(!myFile.is_open()) {
    cerr << "Issue" << endl;
  }

  string originalContent((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>());
  myFile.close();

  ofstream newFile(outputFileName);
  if(!newFile.is_open()) {
    cerr << "issue" << endl;
  }
  reverse(originalContent.begin(), originalContent.end());
  newFile << originalContent;
  newFile.close();
  cout << "Saved reversed content to " << outputFileName << endl;
}

int main() {
  string fileName = "CSC450_CT5_mod5.txt";
  string outputFileName = "CSC450-mod5-reverse.txt";
  writeUserInputToFile(fileName);
  reverseFileContents(fileName, outputFileName);

  return 0;
}