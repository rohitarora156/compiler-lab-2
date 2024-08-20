#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

bool isKeyword(string word) {
    unordered_set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
        "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    return keywords.find(word) != keywords.end();
}

bool isIdentifier(string word) {
    if (word.empty() || isdigit(word[0]) || isKeyword(word)) return false;
    for (char c : word) {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

int main() {
    string filepath;
    cout << "Enter the file path: ";
    cin >> filepath;

    ifstream file(filepath);
    if (!file) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int identifierCount = 0;
    int constantCount = 0;
    int otherCharCount = 0;
    string word;

    while (file >> word) {
        wordCount++;
        if (isIdentifier(word)) {
            identifierCount++;
        } else {
            bool isConstant = true;
            for (char c : word) {
                if (!isdigit(c)) {
                    isConstant = false;
                    break;
                }
            }
            if (isConstant) {
                constantCount++;
            }
        }
        for (char c : word) {
            if (isalnum(c) || c == '_') {
                charCount++;
            } else {
                otherCharCount++;
            }
        }
    }

    cout << "Total characters: " << charCount << endl;
    cout << "Total words: " << wordCount << endl;
    cout << "Total identifiers: " << identifierCount << endl;
    cout << "Total constants: " << constantCount << endl;
    cout << "Total other characters: " << otherCharCount << endl;

    file.close();
    return 0;
}
