#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> uf;

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
bool uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return false;
    if (X > Y)
        swap(X, Y);
    uf[Y] = X;
    return true;
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int MIN_N = 3, MAX_N = 500;
    int MIN_M = 0, MAX_M = 100'000;

    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readSpace();
    int M = inf.readInt(MIN_M, MAX_M, "M");
    inf.readEoln();

    ensuref(N - 1 <= M, "M must be bigger than N-1");

    uf.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        uf[i] = i;

    int U, V, cnt = N;

    for (int i = 1; i <= M; i++) {
        U = inf.readInt(1, N, format("u_%d", i)), inf.readSpace();
        V = inf.readInt(1, N, format("v_%d", i)), inf.readEoln();
        cnt -= uni(U, V);
    }
    inf.readEof();

    ensuref(cnt == 1, "graph must be connected");

    return 0;
}
