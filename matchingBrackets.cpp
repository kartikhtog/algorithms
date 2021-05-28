#include <iostream>
#include <Stack>
using namespace std;

string brackete = "{}{}[][]{{{}}}{[]}((()){"; // non matching brackets
// string brackete = "{}{}[][]{{{}}}{[]}"; // matching brackets
std::stack<char> matchS;
char reverseBracket(char c) {
    char returnValue = c;
    switch(c) {
        case '(':
            returnValue = ')';
            break;
        case '{':
            returnValue = '}';
            break;
        case '[':
            returnValue = ']';
            break;
        
        case ')':
            returnValue = '(';
            break;
        case '}':
            returnValue = '{';
            break;
        case ']':
            returnValue = '[';
            break;
        default:
            returnValue = 'x';
            break;
    }
    return returnValue;
}
bool matchBrackets() {
    for(int i =0;i<brackete.length() ;i++){
        if( (!matchS.empty())  && ( matchS.top() == reverseBracket(brackete[i])) ) {
            cout << "element popped <- " << matchS.top() << endl;
            matchS.pop();
        } else {
            cout << "element pushed -> " << brackete[i] << endl;
            matchS.push(brackete[i]);
        }
    }
    if (matchS.empty()){
        return true;
    }
    return false;
}


int main() {
    if (matchBrackets()) {
        cout<< "brackets matched" << endl;
    } else {
        cout<< "brackets Not matched" << endl;
    }
    return 0;

}