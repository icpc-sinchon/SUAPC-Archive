#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

struct SCC {
    int n, cnt;
    vector<vector<int>> G, scc;
    vector<int> id, fin, S, scc_id;

    SCC(int n) : n(n), cnt(0), G(n) {
        id = fin = scc_id = vector<int>(n);
    }

    void add_edge(int u, int v) {
        G[u].push_back(v);
    }

    int dfs(int v) {
        int top = id[v] = ++cnt;
        S.push_back(v);

        for (int nx : G[v]) {
            if (!id[nx]) {
                top = min(top, dfs(nx));
            } else if (!fin[nx]) {
                top = min(top, id[nx]);
            }
        }

        if (top == id[v]) {
            scc.emplace_back();

            while (!S.empty()) {
                int nx = S.back();
                S.pop_back();

                fin[nx] = 1;
                scc_id[nx] = (int)scc.size() - 1;
                scc.back().push_back(nx);

                if (nx == v) break;
            }
        }

        return top;
    }

    bool strongly_connected() {
        for (int v = 0; v < n; v++) {
            if (!id[v]) dfs(v);
        }

        return scc.size() == 1;
    }
};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, MAX_N, "N");
    inf.readSpace();

    int M = inf.readInt(N, MAX_M, "M");
    inf.readSpace();

    int Q = inf.readInt(1, MAX_Q, "Q");
    inf.readSpace();

    int K = inf.readInt(1, MAX_K, "K");
    inf.readEoln();

    (void)K;

    SCC graph(N);

    for (int i = 1; i <= M; i++) {
        int a = inf.readInt(1, N, "a");
        inf.readSpace();

        int b = inf.readInt(1, N, "b");
        inf.readSpace();

        int c = inf.readInt(0, MAX_C, "c");
        inf.readEoln();

        ensuref(a != b, "Edge %d is a self-loop: %d -> %d.", i, a, b);

        --a;
        --b;
        graph.add_edge(a, b);
        (void)c;
    }

    ensuref(graph.strongly_connected(), "The given directed graph is not strongly connected.");

    for (int i = 1; i <= Q; i++) {
        int u = inf.readInt(1, N, "u");
        inf.readSpace();

        int v = inf.readInt(1, N, "v");
        inf.readEoln();
        
        ensuref(u != v, "Query %d is a same node %d", i, u);
    }

    inf.readEof();
}