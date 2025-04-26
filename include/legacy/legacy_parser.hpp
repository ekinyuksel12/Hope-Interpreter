#include <iostream>
#include <string>
#include <boost/any.hpp>
#include "lexer.hpp"

using namespace std;

namespace Node{
    class Node{
        public:
        Node(boost::any parent, boost::any lchild, boost::any rchild){
            parentNode = parent;
            LeftChildNode = lchild;
            RightChildNode = rchild;
        }

        Node(string number){
            parentNode = TokenTypes::INTEGER;
            LeftChildNode = number;
            RightChildNode = number;
        }

        boost::any parentNode;
        boost::any LeftChildNode;
        boost::any RightChildNode;
    };

    class Number{
        public:
        Number(Token GivenToken){
            token = GivenToken;
        }

        Token token;
    };

    class BinOperator{
        public:
        BinOperator(Token GivenToken){
            token = GivenToken;
        }

        Token token;
    };
}

class Parser{
    public:
    Parser(){
        lexer = Lexer();
        curr_token = Token();
    }

    Parser(Lexer lex){
        lexer = lex;
        curr_token = lexer.get_next_token();
    }

    Node::Node NUM_PAREN(){
        if (curr_token.type == TokenTypes::INTEGER)
        {
            curr_token = lexer.get_next_token(curr_token, TokenTypes::INTEGER);
            return Node::Node(curr_token.value);
        }else if (curr_token.type == TokenTypes::LPAREN){
            curr_token = lexer.get_next_token(curr_token, TokenTypes::LPAREN);
            Node::Node node = ADD_SUB();
            curr_token = lexer.get_next_token(curr_token, TokenTypes::RPAREN);
            return node;
        }
        
    }

    Node::Node MUL_DIV(){
        Node::Node node = NUM_PAREN();

        while (curr_token.type == TokenTypes::PLUS 
            || curr_token.type == TokenTypes::MINUS)
        {
            if (curr_token.type == TokenTypes::MULTIPLY)
            {
                curr_token = lexer.get_next_token(curr_token, TokenTypes::MULTIPLY);
            }else{
                curr_token = lexer.get_next_token(curr_token, TokenTypes::DIVIDE);
            }

            node = Node::Node(curr_token.type, node, NUM_PAREN());
        }
        return node;
    }

    Node::Node ADD_SUB(){
        Node::Node node = MUL_DIV();

        while (curr_token.type == TokenTypes::PLUS 
            || curr_token.type == TokenTypes::MINUS)
        {
            if (curr_token.type == TokenTypes::PLUS)
            {
                curr_token = lexer.get_next_token(curr_token, TokenTypes::PLUS);
            }else{
                curr_token = lexer.get_next_token(curr_token, TokenTypes::MINUS);
            }

            node = Node::Node(curr_token.type, node, MUL_DIV());
        }
        return node;
    }

    Node::Node parse(){
        return ADD_SUB();
    }

    Lexer lexer;
    Token curr_token;
};