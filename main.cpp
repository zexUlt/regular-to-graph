#include "RegExprParser.h"

#include <string>

int main(int argc, char* argv[]) {
    if(argc > 1){
        std::string inFilePath(argv[1]);

        RegExprParser parser(inFilePath);
    }
    return 0;
}


