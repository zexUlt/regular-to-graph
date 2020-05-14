#include "RegExprParser.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
//    if(argc > 1){
//        std::string inFilePath(argv[1]);
//
//        RegExprParser parser(inFilePath);
//    }
    RegExprParser parser("../in.txt");

    auto expr = parser.getRPN_expr();
    for(auto x : expr){
        std::cout << x << " ";
    }
    return 0;
}


