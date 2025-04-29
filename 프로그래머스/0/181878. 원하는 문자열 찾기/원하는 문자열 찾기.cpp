#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    if(myString.length() < pat.length()) {
        return 0;
    }
    for(int i = 0; i < myString.length(); i++) {
        if(myString[i] >='a' && myString[i] <='z') {
            myString[i] = myString[i] - 32;
        }
    }
    for(int i = 0; i < pat.length(); i++) {
        if(pat[i] >='a' && pat[i] <='z') {
            pat[i] = pat[i] - 32;
        }
    }
    cout << myString << " " << pat;
    for(int i = 0; i <= myString.length() - pat.length(); i++) {
        if(myString[i] == pat[0]) {
            bool check = true;
            for(int j = i; j < i + pat.length(); j++) {
                if(myString[j] != pat[j - i]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                return 1;
            }
        }
    }
    return 0;
}