//
// Created by dgt on 3/14/2021.
//

#ifndef ODA_PRINT_UTILS_H
#define ODA_PRINT_UTILS_H
#include <iostream>

namespace usc::utils{
    static void PrintLn(const std::string& msg){
        std::cout << msg << "\n";
    }

    static void TestPrintLn(const std::string& msg){
        std::cout << "<TEST>: " << msg << "\n";
    }
}

#endif //ODA_PRINT_UTILS_H
