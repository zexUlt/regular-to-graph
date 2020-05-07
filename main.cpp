#include "RegExprParser.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
//    if(argc > 1){
//        std::string inFilePath(argv[1]);
//
//        RegExprParser parser(inFilePath);
//    }
    RegExprParser parser(R"(F:\RegularToGraph\regular-to-graph\in.txt)");

    for(auto x : parser.getRPN_expr()){
        std::cout << x << " ";
    }
    return 0;
}


