#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ofstream outputFile("C:/Users/dell/Desktop/example.txt");
  
    // Open the file for writing
    // outputFile.open("C:/Users/dell/Desktop/example.txt");
    // if (outputFile.is_open()) {
  
    //     // Write data to the file
    //     outputFile << "Hello, World!" << endl;
    //     cout<<"okay"<<endl;
    //     outputFile << 42 << endl;
    //     outputFile.close(); // Close the file
    // }
    // else {
  
    //     // Failed to open the file
    //     cout << "Error opening the file for writing."
    //          << endl;
    //     return 1;
    // }
  
    // Reading from a file
    ifstream inputFile("C:/Users/dell/Desktop/example.txt");
    if (inputFile.is_open()) {
        string line,line1;
        line1 = inputFile.get();
        cout<<line1<<endl;
        while (getline(inputFile, line)) {
            // Print each line
            // cout<<"okay"<<endl;
            cout << line << endl;
        }
        // Close the file
        inputFile.close();
    }
    else {
  
        // Failed to open the file
        cout << "Error opening the file for reading."
             << endl;
        return 1;
    }
  
    return 0;
}