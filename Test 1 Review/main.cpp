// Juan Angel Sosa Sosa
// Programming Fundamentals II
// Review for Exam 1. This app has function declarations at the top for notes clarity.

#include <iostream>
#include <string>
#include <fstream> // To use ifstream and

using namespace std;

// Storage of files in the hard-drive and memory
// Hard-drive:
// -    Files are stored permanently(persistent) on devices like HDDs, SSDs, or flash drives.
// -    Data remains even after the computer is powered off.
// Memory:
// -    Files are loaded into RAM (Random Access Memory) for temporary use.
// -    Data is lost when the program or computer shuts down.
// -    Much faster than storage devices, allowing quick access and manipulation of data.
// -    Uses buffers and caches to improve performance before writing back to disk.

// Sequential vs. Random-acess files


// Input file:
void inputFile(const string& filename) {
    // Step 1: Include the <fstream> header at the beginning of the program.
    // Step 2: Declare an ifstream object.
    ifstream file;
    
    // Step 3: Open the file using the open() method.
    file.open(filename);
    
    // Step 4: Check if the file was successfully opened.
    if (!file) {
        cout << "Error opening file!";
        return;
    }
    
    // Step 5: Read data from the file.
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    // Step 6: Close the file to release resources.
    file.close();
}



int main() {
    
    string filename = "data.txt";
    inputFile(filename);

    return 0;
}
