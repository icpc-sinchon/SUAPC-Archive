#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 501;
const int MAX_M = 100'001;

int U[MAX_M], V[MAX_M], D[MAX_N];
vector<int> adj[MAX_N];

int get_radius(int N, vector<int> edges) {
    queue<int> q;
    int res = N + 1, X;

    for (int i : edges)
        adj[U[i]].push_back(V[i]), adj[V[i]].push_back(U[i]);

    for (int i = 1; i <= N; i++) {
        fill(D + 1, D + N + 1, -1);
        q.push(i), D[i] = 0;

        while (!q.empty()) {
            X = q.front(), q.pop();
            for (int j : adj[X])
                if (D[j] == -1)
                    q.push(j), D[j] = D[X] + 1;
        }
        if (*min_element(D + 1, D + N + 1) != -1)
            res = min(res, *max_element(D + 1, D + N + 1));
    }

    for (int i = 1; i <= N; i++)
        adj[i].clear();
    return res;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int N, M, rad_G, rad_T, X;
    vector<int> adj_G, adj_T;

    N = inf.readInt(), M = inf.readInt();
    for (int i = 1; i <= M; i++) {
        U[i] = inf.readInt(), V[i] = inf.readInt();
        adj_G.push_back(i);
    }

    rad_G = get_radius(N, adj_G);

    for (int i = 1; i < N; i++) {
        X = ouf.readInt(1, M, format("edge_id[%d]", i));
        adj_T.push_back(X);
    }
    if (!ouf.seekEof())
        quitf(_pe, "extra tokens after %d edge indices", N - 1);

    rad_T = get_radius(N, adj_T);

    if (rad_G != rad_T)
        quitf(_wa, "Spanning tree radius is %d, but graph radius is %d", rad_T, rad_G);
    quitf(_ok, "Correct! Spanning tree radius matches graph radius (%d)", rad_G);
}
