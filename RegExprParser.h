//
// Created by ZexUlt on 06.05.2020.
//

#ifndef REGULAR_TO_GRAPH_REGEXPRPARSER_H
#define REGULAR_TO_GRAPH_REGEXPRPARSER_H

#include "Operation.h"

#include <string>
#include <stack>
#include <map>
#include <vector>

class RegExprParser {
public:
    explicit RegExprParser() = default;
    explicit RegExprParser(const std::string& pRegExprFile);

    std::vector<std::string> getRPN_expr() const;

    std::vector<std::string> alphabet;
private:
    void transformToRPN();
    void beautify();
    static bool inline isBracket(const std::string& sym);
    bool ensureAlphabet(const std::string& sym);


    std::vector<std::string> reg_expr;
    std::string operationSym = "*+|";
    std::vector<std::string> rpn_reg_expr;
    std::stack<std::string> tStack;
    const std::map<std::string , int> priority = {
            {")", 0},
            {"(", 1},
            {"|", 2},
            {"+", 3},
            {"*", 4}
    };
};


#endif //REGULAR_TO_GRAPH_REGEXPRPARSER_H
