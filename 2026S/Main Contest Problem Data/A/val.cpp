#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 100, "N"); inf.readEoln();
    string S = inf.readToken("[A-Z0-9]+", "S"); inf.readEoln(); inf.readEof();
    ensuref(S.size() == N, "length unmatched"); return 0;
}