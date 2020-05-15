//
// Created by ZexUlt on 06.05.2020.
//

#include "RegExprParser.h"

#include <fstream>
#include <iostream>

RegExprParser::RegExprParser(const std::string &pRegExprFile) {
    std::ifstream read(pRegExprFile);
    std::string alph, expr;

    std::getline(read, alph);
    std::getline(read, expr);

    int space_pos = expr.find(' ');
    while (space_pos != std::string::npos) {
        expr.erase(space_pos, 1);
        space_pos = expr.find(' ');
    }

    read.close();

    unsigned pos = alph.find_first_of(' ');
    int begin_pos = 0;
    while (pos != std::string::npos) { // Reading all symbols delimited with space
        alphabet.push_back(alph.substr(begin_pos, pos - begin_pos));
        begin_pos = pos + 1;
        pos = alph.find_first_of(' ', pos + 1);
    }
    pos = alph.find_last_of(' ');
    alphabet.push_back(alph.substr(pos + 1)); // Reading last symbol

    if (!expr.empty()){
        for (auto i = 0; i < expr.size(); i++) {
            if (isBracket(std::string(1, expr[i]))) {
                reg_expr.emplace_back(std::string(1, expr[i]));
            } else if (operationSym.find(expr[i]) != std::string::npos) {
                reg_expr.emplace_back(std::string(1, expr[i]));
            } else {
                std::string recognizedLetter(1, expr[i]);
                while (!ensureAlphabet(recognizedLetter)) {
                    recognizedLetter += expr[++i];
                }
                reg_expr.emplace_back(recognizedLetter);
            }
        }

        beautify();

        for (const auto &x : reg_expr) {
            std::cout << x;
        }
        std::cout << std::endl;

        transformToRPN();
    } else {
        rpn_reg_expr = std::vector<std::string>();
    }
}

bool RegExprParser::isBracket(const std::string& c)
{
    return c == ")" || c == "(";
}

bool RegExprParser::ensureAlphabet(const std::string& sym)
{
    bool isExists = false;
    for(const auto& letter : alphabet){
        if(sym == letter)
            isExists = true;
    }
    return isExists;
}

void RegExprParser::beautify()
{
    for(int i = 0; i < this->reg_expr.size() - 1; i++){
        auto cond1 = ensureAlphabet(reg_expr[i]) && ensureAlphabet(reg_expr[i + 1]); // ab -> a.b
        auto cond2 = ensureAlphabet(reg_expr[i]) && (reg_expr[i + 1] == "("); // a( -> a . (
        auto cond3 = (reg_expr[i] == ")") && ensureAlphabet(reg_expr[i + 1]); // )a -> ) . a
        auto cond4 = (reg_expr[i] == "*") && ensureAlphabet(reg_expr[i + 1]); // *a -> * . a
        auto cond5 = (reg_expr[i] == "+") && ensureAlphabet(reg_expr[i + 1]); // +a -> +.a
        auto cond6 = (reg_expr[i] == ")") && (reg_expr[i + 1] == "("); // )( -> ) . (

        if(cond1 || cond2 || cond3 || cond4 || cond5 || cond6) {
            this->reg_expr.insert(reg_expr.begin() + i + 1, ".");
            i++;
        }

    }
}

void RegExprParser::transformToRPN()
{
    for(auto it = this->reg_expr.begin(); it != this->reg_expr.end(); it++){
        if(*it == ")"){ // If next symbol is ')'
            while(tStack.top() != "("){ // Pop all operations from stack until there is not '('
                    this->rpn_reg_expr.emplace_back(this->tStack.top());
                this->tStack.pop();
            }
            this->tStack.pop();
        }

        if(ensureAlphabet(*it)) {
            this->rpn_reg_expr.emplace_back(*it);
        }

        if(*it == "("){
            this->tStack.push(*it);
        }

        if(this->operationSym.find(*it) != std::string::npos) {
            if (this->tStack.empty()) {
                this->tStack.push(*it);
            } else {
                if (this->priority.at(this->tStack.top()) < this->priority.at(*it)) {
                    this->tStack.push(*it);
                } else {
                    while ( !this->tStack.empty() && (this->priority.at(this->tStack.top()) >= this->priority.at(*it)) ) {
                        this->rpn_reg_expr.emplace_back(this->tStack.top());
                        this->tStack.pop();
                    }
                    this->tStack.push(*it);
                }
            }
        }
    }

    while (!this->tStack.empty()){
        if(!isBracket(this->tStack.top())){
            this->rpn_reg_expr.emplace_back(this->tStack.top());
        }
        this->tStack.pop();
    }
}

std::vector<std::string> RegExprParser::getRPN_expr() const
{
    return this->rpn_reg_expr;
}
