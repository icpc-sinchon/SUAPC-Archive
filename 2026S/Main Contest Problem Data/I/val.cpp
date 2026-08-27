#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int MAX_N = 5000;

    int n = inf.readInt(1, MAX_N, "n");
    inf.readEoln();

    vector<int> p = inf.readInts(n, 1, n, "p");
    inf.readEoln();

    vector<int> appeared(n + 1, 0);

    for (int x : p) {
        ensuref(
            !appeared[x],
            "p is not a permutation: value %d appears multiple times",
            x
        );

        appeared[x] = 1;
    }

    inf.readEof();
}