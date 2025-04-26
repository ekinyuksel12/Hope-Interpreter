#include <iostream>
#include "parser.hpp"

using namespace std;

int main()
{
    system("chcp 1254 > nul");
    string a;

    while (a != "end")
    {
        cout << ">>>";

        getline(std::cin >> std::ws, a);

        Lexer lexer(a);

        Token token;

        token = lexer.get_next_token();

        cout << token.toString() << endl;

        do
        {
            token = lexer.get_next_token();
            cout << token.toString() << endl;
        } while (token.type != "END");
        cout << endl;
    }
}