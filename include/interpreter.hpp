#include <iostream>
#include "lexer.hpp"

using namespace std;
using namespace TokenTypes;

struct Node{
    Node(Token GivenToken){
        value = GivenToken;

        left = NULL;
        right = NULL;
    }

    Node(Token GivenToken, Node* GivenMiddle){
        value = GivenToken;

        left = GivenMiddle;
        right = NULL;
    }

    Node(Token GivenToken, Node* GivenLeft, Node* GivenRight){
        value = GivenToken;

        left = GivenLeft;
        right = GivenRight;
    }

    void error(){
        throw ("Interpreter Error");
    }

    float execute(){
        if (value.type == OP)
        {
            switch (value.value[0])
            {
            case '+':
                return left->execute() + right->execute(); break;
            case '-':
                return left->execute() - right->execute(); break;
            case '*':
                return left->execute() * right->execute(); break;
            case '/':
                return left->execute() / right->execute(); break;
            
            default:
                break;
            }
        }else if (value.type == NUM)
        {
            return stof(value.value);
        }else if(value.type == UNARY){
            if (value.value == "+")
            {
                return left->execute();
            }else if(value.value == "-"){
                return -left->execute();
            }
            
        }else{
            error();
        }
    }

    Token value;
    struct Node* left;
    struct Node* right;
};