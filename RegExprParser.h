//
// Created by ZexUlt on 06.05.2020.
//

#ifndef REGULAR_TO_GRAPH_REGEXPRPARSER_H
#define REGULAR_TO_GRAPH_REGEXPRPARSER_H

#include "Operation.h"

#include <string>
#include <stack>
#include <map>

class RegExprParser {
public:
    explicit RegExprParser() = default;
    explicit RegExprParser(const std::string& pRegExprFile);

    std::string getRPN_expr() const;
private:
    void transformToRPN();
    void beautify();
    static bool inline isBracket(char c);

    std::string reg_expr;
    std::string operationSym = "*+|";
    std::string rpn_reg_expr;
    std::stack<char> tStack;
    const std::map<char, int> priority = {
            {')', 0},
            {'(', 1},
            {'|', 2},
            {'+', 3},
            {'*', 4}
    };
};


#endif //REGULAR_TO_GRAPH_REGEXPRPARSER_H
