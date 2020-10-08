//
//  funFiles.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 07/10/2020.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileTest () {
    string path = "/Users/francescogalassi/Desktop/filename.txt";
  // Create a text file
  ofstream MyWriteFile(path);//added a path otherwise lost in temporary files

  // Write to the file
  MyWriteFile << "Dai abbastanza fico \nnewline deve andare attaccato sennò lascia lo spazio \n così \n Files can be tricky, but it is fun enough!";
 
  // Close the file
  MyWriteFile.close();

  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile(path);

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText<<endl;
  }

  // Close the file
  MyReadFile.close();
}

