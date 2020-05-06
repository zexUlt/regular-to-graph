//
// Created by ZexUlt on 06.05.2020.
//

#include "RegExprParser.h"

#include <fstream>

RegExprParser::RegExprParser(const std::string &pRegExprFile)
{
    std::ifstream read(pRegExprFile);

    read >> reg_expr;

    read.close();
}