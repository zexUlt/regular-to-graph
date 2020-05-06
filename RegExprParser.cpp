//
// Created by ZexUlt on 06.05.2020.
//

#include "RegExprParser.h"

#include <fstream>
#include <iostream>

RegExprParser::RegExprParser(const std::string &pRegExprFile)
{
    std::ifstream read(pRegExprFile);

    read >> reg_expr;

    read.close();

    beautify();

    transformToRPN();
}

bool RegExprParser::isBracket(char c)
{
    return c == ')' || c == '(';
}

void RegExprParser::beautify()
{
    for(auto it = this->reg_expr.begin(); it != this->reg_expr.end() - 1; it++){
        auto cond1 = !isBracket(*it) && (this->operationSym.find(*it) == std::string::npos) &&
                !isBracket(*(it + 1)) && (this->operationSym.find(*(it + 1)) == std::string::npos); // ab -> a+b
        auto cond2 = (this->operationSym.find(*it) == std::string::npos) && ( *(it + 1) == '('); // a( -> a + (
        auto cond3 = (*it == ')')  && ((this->operationSym.find(*(it + 1)) == std::string::npos)); // )a -> ) + a
        auto cond4 = (*it == '*') && (this->operationSym.find(*(it + 1) == std::string::npos)); // *a
        auto cond5 = (*it == ')' && (*(it + 1) == '(')); // )( -> ) + (


        if(cond1 || cond2 || cond3 || cond4 || cond5) {
            this->reg_expr.insert(it + 1, '+');
            it++;
        }

    }
}

void RegExprParser::transformToRPN()
{
    for(auto it = this->reg_expr.begin(); it != this->reg_expr.end() - 1; it++){
        if(*it == ')'){ // If next symbol is ')'
            while(tStack.top() != '('){ // Pop all operations from stack until there is not '('
                    this->rpn_reg_expr += this->tStack.top();
                this->tStack.pop();
            }
        }

        if(*it == '('){
            this->tStack.push(*it);
        }

        if(this->operationSym.find(*it) == std::string::npos && !isBracket(*it)){
            this->rpn_reg_expr += *it;
        } else if(this->tStack.empty() || this->priority.at(this->tStack.top()) < this->priority.at(*it)){
            this->tStack.push(*it);
        } else {
            std::cout << this->priority.at(this->tStack.top()) << std::endl;
            std::cout << this->priority.at(*it) << std::endl;
            while(!this->tStack.empty() && (this->priority.at(this->tStack.top()) >= this->priority.at(*it))){
                if(this->tStack.top() != '(') {
                    this->rpn_reg_expr += this->tStack.top();
                    this->tStack.pop();
                } else break;

            }
        }
    }

    while (!this->tStack.empty()){
        if(!isBracket(this->tStack.top())){
            this->rpn_reg_expr += this->tStack.top();
        }
        this->tStack.pop();
    }
}

std::string RegExprParser::getRPN_expr() const
{
    return this->rpn_reg_expr;
}
