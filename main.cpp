#include "RegExprParser.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
//    if(argc > 1){
//        std::string inFilePath(argv[1]);
//
//        RegExprParser parser(inFilePath);
//    }
    RegExprParser parser("F:\\RegularToGraph\\regular-to-graph\\in.txt");

    std::cout << parser.getRPN_expr();
    return 0;
}


