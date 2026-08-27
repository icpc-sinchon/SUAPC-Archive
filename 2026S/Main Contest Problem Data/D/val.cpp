#include "testlib.h"
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MIN_SL = 2, MAX_SL = 500'000;
bool chk(string s){
    ensuref(MIN_SL <= s.size() && s.size() <= MAX_SL, "Length: %d", s.size());
    stack<char> stk; for (char c : s){
        if (c == '(' || c == '{' || c == '['){ stk.push(c); }
        else if (c == ')' || c == '}' || c == ']'){
            if (stk.empty()){ return 0; }
            char p = stk.top(); stk.pop();
            if (p == '(' && c != ')'){ return 0; }
            if (p == '{' && c != '}'){ return 0; }
            if (p == '[' && c != ']'){ return 0; }
        }
        else{ return 0; }
    } return stk.empty();
}

int main(int argc, char **argv){ registerValidation(argc, argv);
    string s = inf.readToken(); inf.readEoln();
    string t = inf.readToken(); inf.readEoln();
    ensuref(chk(s), "S is not RBS"); ensuref(chk(t), "T is not RBS");
    inf.readEof();
}