#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;

    DSU(int n) : p(n + 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        p[y] = x;
        return true;
    }
};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 300000, "N");
    inf.readEoln();

    DSU dsu(N);

    for (int i = 1; i <= N - 1; i++) {
        int u = inf.readInt(1, N, "u");
        inf.readSpace();
        int v = inf.readInt(1, N, "v");
        inf.readEoln();

        ensuref(u != v, "Self-loop at edge %d: (%d, %d)", i, u, v);
        ensuref(dsu.merge(u, v),
                "Edge %d creates a cycle: (%d, %d)", i, u, v);
    }

    inf.readEof();
}