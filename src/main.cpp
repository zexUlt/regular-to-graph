#include "RegExprParser.hpp"
#include "Graph.hpp"

#include <string>
#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
   if(argc > 1){
        std::string inFilePath(argv[1]);

        RegExprParser parser(inFilePath);
        auto expr = parser.getRPN_expr();
        
        std::unique_ptr<Graph> g_ptr;
        
        g_ptr->construction(expr);

        for(auto x : expr){
            std::cout << x << " ";
        }

    }else{
        std::cout << "Not enough parameters!\n"; 
    }

    return 0;
}


