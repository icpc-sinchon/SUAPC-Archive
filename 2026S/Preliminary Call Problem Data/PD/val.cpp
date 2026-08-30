#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    registerValidation(argc, argv);

    inf.readInt(1, 1'000'000'000, "seed");
    inf.readEoln();

    int T = inf.readInt(1, 1'000, "T");
    inf.readEoln();

    long long sumN = 0;
    long long sumM = 0;

    for (int tc = 1; tc <= T; ++tc) {
        int N = inf.readInt(2, 200'000, "N");
        inf.readSpace();
        int M = inf.readInt(1, 200'000, "M");
        inf.readEoln();

        ensuref(1LL * M <= 1LL * N * (N - 1) / 2,
                "test case %d: too many edges for a simple graph", tc);

        sumN += N;
        sumM += M;

        ensuref(sumN <= 200'000,
                "sum of N exceeds 200000 at test case %d", tc);
        ensuref(sumM <= 200'000,
                "sum of M exceeds 200000 at test case %d", tc);

        set<pair<int, int>> used;

        for (int i = 1; i <= M; ++i) {
            int u = inf.readInt(1, N, "u_i");
            inf.readSpace();
            int v = inf.readInt(1, N, "v_i");
            inf.readEoln();

            ensuref(u != v,
                    "test case %d, edge %d: loop is not allowed", tc, i);

            if (u > v)
                swap(u, v);

            ensuref(used.insert({u, v}).second,
                    "test case %d, edge %d: duplicated edge", tc, i);
        }
    }

    inf.readEof();
}