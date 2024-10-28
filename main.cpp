#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void reverseFile();

int main() {
    std::string userInput;

    // get input
    std::cout << "Enter text to add to the CSC450_CT5_mod5.txt file: ";
    std::getline(std::cin, userInput);

    // append to CSC450_CT5_mod5.txt
    std::ofstream outfile("CSC450_CT5_mod5.txt", std::ios_base::app); // open file in append mode
    if (outfile.is_open()) {
        outfile << userInput << std::endl;
        outfile.close();
        std::cout << "Added text to CSC450_CT5_mod5.txt" << std::endl;
    } else {
        std::cerr << "Error, cant open CSC450_CT5_mod5.txt" << std::endl;
        return 1;
    }

    // call reverseFile func
    reverseFile();

    return 0;
}

void reverseFile() {
    // read CSC450_CT5_mod5.txt
    std::ifstream infile("CSC450_CT5_mod5.txt");
    if (!infile.is_open()) {
        std::cerr << "Error, cant open CSC450_CT5_mod5.txt for reading." << std::endl;
        return;
    }

    // read entire contents into string
    std::string contents((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    // reverse string
    std::reverse(contents.begin(), contents.end());

    // write reversed contents to CSC450-mod5-reverse.txt
    std::ofstream outfile("CSC450-mod5-reverse.txt"); // open with overwrite mode
    if (outfile.is_open()) {
        outfile << contents;
        outfile.close();
        std::cout << "Reversed & written to CSC450-mod5-reverse.txt." << std::endl;
    } else {
        std::cerr << "Error, cant open CSC450-mod5-reverse.txt for writing." << std::endl;
    }
}