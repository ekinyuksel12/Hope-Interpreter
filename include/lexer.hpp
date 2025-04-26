#include <iostream>
#include <string>

using namespace std;

namespace TokenTypes{
    string NUM = "NUM", STRING = "STRING";
    string LPAREN = "LPAREN", RPAREN = "RPAREN";
    string FUNC = "FUNC";
    string OP = "OP", UNARY = "UNARY";
    string END = "END";
}

using namespace TokenTypes;

class Token{
    public:
    Token(){
        type = "NULL";
        value = "NULL";
    }

    Token(string token_type, string token_value){
        type = token_type;
        value = token_value;
    }

    string toString(){
        return "Token(" + type + ", " + value +")";
    }

    string type;
    string value;
};

class Lexer{
    public:
    Lexer(){
        text = "";
        pos = 0;
    }

    Lexer(string inputText){
        text = inputText;
        pos = 0;
        curr_char = text[0];
    }

    Token get_next_token(){
        while (curr_char != 0)
        {
            if (isspace(curr_char))
            {
                skip_whitespace();
            }

            if (isdigit(curr_char))
            {
                return Token(NUM, get_number());
            }

            if (isalpha(curr_char) || string("üðþöçýÜÐÞÝÇÖ").find(curr_char) != string::npos)
            {
                return Token(FUNC, get_func());
            }

            if (curr_char == '"'){
                return Token(STRING, get_string());
            }

            switch (curr_char)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                advance();
                return Token(OP, string(1, text[pos - 1])); break;
            case '(':
                advance();
                return Token(LPAREN, "("); break;
            case ')':
                advance();
                return Token(RPAREN, ")"); break;
            default:
                break;
            }

            error();
        }

        return Token(END, "END");        
    }

    private:
    void error(){
        throw("Lexer error");
    }

    void skip_whitespace(){
        while (isspace(curr_char) && curr_char != 0)
        {
            advance();
        }
    }

    string get_number(){
        string number = "";

        while ((isdigit(curr_char) || curr_char == '.') && curr_char != 0)
        {
            number += curr_char;
            advance();
        }
        
        return number;
    }

    string get_func(){
        string function = "";

        while ((isalpha(curr_char) || string("üðþöçýÜÐÞÝÇÖ").find(curr_char) != string::npos) && curr_char != 0)
        {
            function += curr_char;
            advance();
        }
        
        return function;
    }

    string get_string(){
        string result;
        advance();

        while (curr_char != '"' && curr_char != 0)
        {
            result += curr_char;
            advance();
        }

        advance();
        return result;
    }

    void advance(){
        pos++;
        
        if (pos > text.length() - 1)
        {
            curr_char = 0;
        }else{
            curr_char = text[pos];
        }
    }

    int pos = 0;
    string text = "";
    
    char curr_char;
    Token curr_token;
};