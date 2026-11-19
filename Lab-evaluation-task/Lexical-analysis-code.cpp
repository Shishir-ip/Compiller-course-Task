#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isDigitChar(char c) {
    return (c >= '0' && c <= '9');
}

bool isAlphaChar(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

bool isAlnumChar(char c) {
    return (isAlphaChar(c) || isDigitChar(c));
}

bool isKeyword(string str) {
    string keywords[] = {"int", "float", "double", "char", "if", "else", "while", "for", "return", "void","cout" , "cin"};
    int numKeywords = 12;
    for (int i = 0; i < numKeywords; i++) {
        if (str == keywords[i]) return true;
    }
    return false;
}

bool isOperator(string str) {
    string operators[] = {"=", "+", "-", "*", "/", "==", "!=", "<", ">", "<=", ">=","<<",">>"};
    int numOps = 13;
    for (int i = 0; i < numOps; i++) {
        if (str == operators[i]) return true;
    }
    return false;
}

bool isSeparator(string str) {
    string separators[] = {"{", "}", "(", ")", ";", ","};
    int numSeps = 6;
    for (int i = 0; i < numSeps; i++) {
        if (str == separators[i]) return true;
    }
    return false;
}

bool isConstant(string str) {
    bool decimalPoint = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (decimalPoint) return false;
            decimalPoint = true;
        } else if (!isDigitChar(str[i])) {
            return false;
        }
    }
    return true;
}

bool isIdentifier(string str) {
    if (!isAlphaChar(str[0])) return false;
    for (int i = 1; i < str.length(); i++) {
        if (!isAlnumChar(str[i])) return false;
    }
    return true;
}

string classifyToken(string token) {
    if (isKeyword(token)) return "[Keyword]";
    else if (isOperator(token)) return "[Operator]";
    else if (isSeparator(token)) return "[Separator]";
    else if (isConstant(token)) return "[Constant]";
    else if (isIdentifier(token)) return "[Identifier]";
    else return "[Unknown]";
}

int main() {
    string myText;
    ifstream MyReadFile("token.txt");
    ofstream MyWriteFile("output.txt");

    if (!MyReadFile.is_open()) {
        cout << "Error: Could not open token.txt!" << endl;
        return 1;
    }

    if (!MyWriteFile.is_open()) {
        cout << "Error: Could not create output.txt!" << endl;
        return 1;
    }

    int lineNum = 0;

    while (getline(MyReadFile, myText)) {
        lineNum++;

        string token = "";
        for (int i = 0; i <= myText.length(); i++) {
            if (i == myText.length() || myText[i] == ' ' || myText[i] == '\t' || myText[i] == '\r') {
                if (!token.empty()) {
                    string result = "Line " + to_string(lineNum) + ": Token: " + token + "\t-->\t" + classifyToken(token);

                    cout << result << endl;
                    MyWriteFile << result << endl;

                    token = "";
                }
            } else {
                token += myText[i];
            }
        }
    }

    MyReadFile.close();
    MyWriteFile.close();

    cout << endl<<"Output successfully saved to output.txt" << endl;
    return 0;
}
