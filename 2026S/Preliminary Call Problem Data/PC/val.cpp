#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 200'000, "N");
    inf.readEoln();

    string S = inf.readToken("[A-Z]+", "S");
    inf.readEoln();

    string T = inf.readToken("[A-Z]+", "T");
    inf.readEoln();

    ensuref((int)S.size() == N,
            "The length of S must be N, but |S| = %d and N = %d.",
            (int)S.size(), N);

    ensuref((int)T.size() == N,
            "The length of T must be N, but |T| = %d and N = %d.",
            (int)T.size(), N);

    inf.readEof();

    return 0;
}