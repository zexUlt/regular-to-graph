//
// Created by ZexUlt on 06.05.2020.
//

#ifndef REGULAR_TO_GRAPH_REGEXPRPARSER_H
#define REGULAR_TO_GRAPH_REGEXPRPARSER_H

#include "Operation.h"

#include <string>

class RegExprParser {
public:
    explicit RegExprParser() = default;
    explicit RegExprParser(const std::string& pRegExprFile);

private:
    std::string reg_expr;

};


#endif //REGULAR_TO_GRAPH_REGEXPRPARSER_H
