#include <iostream>
#include "interpreter.hpp"
#include <queue>

using namespace std;
using namespace TokenTypes;

void printLevelOrder(Node *root){
    if (root == NULL) return;  
    queue<Node *> q;  

    q.push(root);  

    while (q.empty() == false)  
    {
        int nodeCount = q.size();
        
        while (nodeCount > 0) 
        {  
            Node *node = q.front();  
            cout << node->value.toString() << " ";  
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
        cout << endl;  
}}

class Parser{
    public:
    Parser(Lexer GivenLexer){
        lexer = GivenLexer;

        curr_token = lexer.get_next_token();
    }
    
    Node* parse(){
        return ADD_SUB();
    }

    private:

    Node* NUM_PAREN_UNARY(){
        Token token = curr_token;
        
        if (token.type == NUM)
        {
            eat(NUM);
            Node* node = new Node(token);
            return node;
        }else if(token.type == LPAREN){
            eat(LPAREN);
            Node* node = ADD_SUB();
            eat(RPAREN);
            return node;
        }else if((token.value == "+" || token.value == "-") && token.type == OP){
            eat(OP);
            token.type = UNARY;
            Node* node = new Node(token, NUM_PAREN_UNARY());
            return node;
        }
    }

    Node* MUL_DIV(){
        Node* node = NUM_PAREN_UNARY();

        while ((curr_token.value == "*" || curr_token.value == "/"))
        {
            Token token = curr_token;
            
            eat(OP);

            token.type = OP;
            node = new Node(token, node, NUM_PAREN_UNARY());
        }
        
        return node;
    }

    Node* ADD_SUB(){
        Node* node = MUL_DIV();

        while ((curr_token.value == "+" || curr_token.value == "-"))
        {
            Token token = curr_token;

            eat(OP);

            token.type = OP;
            node = new Node(token, node, MUL_DIV());
        }
        
        return node;
    }

    void error(){
        throw ("Parser error!");
    }

    void eat(string token_type){
        if (curr_token.type == token_type)
        {
           curr_token = lexer.get_next_token();
        }else{
            error();
        }
        
    }

    Lexer lexer;
    Token curr_token;
};