// Juan Angel Sosa Sosa
// Programming Fundamentals II
// Review for Exam 1. This app has function declarations at the top for notes clarity.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

/*
    Sequential vs. Random-Access Files in C++:

    1. **Sequential Files**:
       - Data is stored and accessed in a linear, sequential order, one record after another.
       - The program reads or writes data starting from the beginning of the file and proceeds in a continuous sequence.

    2. **Random-Access Files**:
       - Data is stored in a way that allows direct access to any specific record, without needing to read through other records.
       - The program can jump to any part of the file to read or write data using file pointers or positions.
*/


// Input file example:
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

// Output to file example:
void outputFile (const string& filename) {
    // Step 1: Include the <fstream> header at the beginning of the program.
    // Step 2: Declare an ofstream object
    ofstream file;
    
    // Step 3: Open the file (creates if not exists, overwrites if exists)
    file.open(filename);
    
    // Step 4: Check if the file was successfully opened
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    
    // Step 5: Write data to the file
    file << "Hello, world!\n";
    file << "This is a test file.\n";
    file << "Writing data using ofstream in C++.\n";

    // Step 6: Close the file
    file.close();
}

// Syntax of creating and using string stream objects
void usingStringStreamObjects(const string& input) {
    // Step 1: Include the <sstream> header for stringstream operations.
    // Step 2: Declare a stringstream object.
        stringstream ss(input);
    
    // Step 3: Declare variables to store extracted data.
        int num1, num2;
        double decimal;
        string word;
    
    // Step 4: Extract data from the stringstream (reading).
    ss >> num1 >> num2 >> decimal >> word;
    
    // Step 5: Process the extracted data (e.g., perform operations).
    cout << "Extracted values: " << num1 << ", " << num2 << ", " << decimal << ", " << word << endl;
    
    // Step 6: Write formatted data into the stringstream (writing).
    stringstream output;
    output << "Sum of numbers: " << (num1 + num2) << ", Decimal: " << decimal;

    // Step 7: Retrieve and display the formatted output.
    string result = output.str();  // Convert stream to string.
    cout << "Formatted output: " << result << endl;
}

// Structure and syntax
void createStructure() {
    // Step 1: Declare and define a structure
    struct Person {
        string name;
        int age;
    };

    // Step 2: Create a datatype of the structure
    Person person1;
    person1.name = "Alice";
    person1.age = 30;

    // Step 3: Output the structure's data
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
}

int main() {
    string filename = "data.txt";
    string input = "10 20 3.14 Hello";
    
//    inputFile(filename);
//    outputFile(filename);
//    usingStringStreamObjects(input);
//    createStructure();

    return 0;
}

/*
    Stream and Buffer 

    1. **Stream**:
       - A stream represents a sequence of bytes flowing into or out of a program.
       - It abstracts input and output operations, allowing uniform handling of different data sources (e.g., files, consoles).
       - Types of Streams:
         - **Input Stream (`istream`)**: Used for reading data (e.g., `std::cin`, `std::ifstream`).
         - **Output Stream (`ostream`)**: Used for writing data (e.g., `std::cout`, `std::ofstream`).
         - **Bidirectional Stream (`iostream`)**: Used for both input and output (e.g., `std::fstream`).
       - Streams can be associated with various devices, including files, keyboard input, or memory.

    2. **Buffer**:
       - A buffer is a temporary storage area (typically in memory) where data is held before being processed.
       - Buffers optimize performance by reducing the number of I/O operations, allowing data to be processed in larger chunks rather than byte-by-byte.
       - For input streams, data is first read into a buffer before being retrieved by the program. For output streams, data is written to a buffer before being flushed to its destination.
       - The standard library handles buffering automatically, but it can be customized for performance (e.g., `std::ios::unitbuf`).

    3. **Stream Buffering**:
       - **Input Buffering**: When reading from a stream (e.g., `std::cin`), data is buffered until a certain delimiter (e.g., newline) or EOF is encountered.
       - **Output Buffering**: For output streams (e.g., `std::cout`), data is buffered and flushed to the output device either when the buffer is full or when certain events (like calling `std::endl`) trigger a flush.
       - **Manual Buffer Control**: Stream buffering can be disabled or controlled with flags like `std::unitbuf` for immediate flushing or `std::nounitbuf` for regular buffering.

    4. **Why Buffers Are Important**:
       - **Performance**: Reduces the number of costly I/O operations, especially when dealing with files and networks.
       - **Efficiency**: Speeds up data reading/writing by processing data in chunks, leading to more efficient handling of large datasets.
       - **Optimized Resource Usage**: Minimizes overhead by reducing direct interaction with hardware devices (like the disk or network).
*/

/*
    Passing by Value vs Passing by Reference in C++:

    1. **Passing by Value**:
       - When a function parameter is passed by value, a **copy** of the argument is passed to the function.
       - The function works with the copy, so any changes made to the parameter inside the function **do not affect** the original argument.
       - **Memory Access**: The copy of the variable is stored in a new memory location, independent of the original variable. The original variable's memory is not affected.
       - **Memory Storage**: The copy of the argument is typically stored on the stack (for primitive types), separate from the original variable.
       - **Advantages**:
         - Simplicity: The function works with a copy of the data.
         - Safety: Since the original data is not modified, there is no risk of unintended side effects.
       - **Disadvantages**:
         - Performance: Passing large objects by value can be inefficient due to the need to copy the object.

    2. **Passing by Reference**:
       - When a function parameter is passed by reference, **the actual memory address** of the argument is passed to the function.
       - The function operates directly on the original data, and any changes made to the parameter inside the function **affect the original argument**.
       - **Memory Access**: The function accesses the memory location of the original argument directly, as the reference is an alias to that memory address.
       - **Memory Storage**: The reference itself does not occupy separate memory for the data, as it shares the memory location of the original variable.
       - **Advantages**:
         - Performance: Passing large objects by reference avoids the cost of copying.
         - Allows modification of the original data within the function.
       - **Disadvantages**:
         - Risk of unintended side effects, as the original data can be modified.
         - Functions can unintentionally change data, which may lead to bugs.
*/

