#include <iostream>
#include <string>
#include "parser.hpp"

using namespace std;

int main(){
    system("chcp 1254 > nul");

    char showAST;

    cout << "S�z Dizimi A�ac� G�sterilsin mi? (e/h)";
    cin >> showAST;
    
    string a;
    
    while (a != "end"){
        cout << ">>>";
        getline(std::cin >> std::ws, a);

        Lexer lexer(a);
        Parser parser(lexer);
        
        Node* node = parser.parse();

        if(showAST == 'e'){printLevelOrder(node); cout << endl;}

        cout << node->execute() << endl;
    }

    return 0;
}