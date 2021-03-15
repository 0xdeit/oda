//
// Created by dgt on 3/14/2021.
//

#ifndef ODA_PRINT_UTILS_H
#define ODA_PRINT_UTILS_H
#include <iostream>

namespace usc::utils{
    // TODO: debug print?
    // TODO: log print?

    // Print a string to stdout with a carriage return at the end.
    static void PrintLn(const std::string& msg){
        std::cout << msg << "\n";
    }

    // Print a string to stdout with "<TEST>:" at the beginning and a carriage return at the end.
    static void TestPrintLn(const std::string& msg){
        std::cout << "<TEST>: " << msg << "\n";
    }
}

#endif //ODA_PRINT_UTILS_H
