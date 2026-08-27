#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;

    DSU(int n) : p(n, -1) {}

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (p[a] > p[b])
            swap(a, b);

        p[a] += p[b];
        p[b] = a;

        return true;
    }
};

int main(int argc, char **argv) {
    registerInteraction(argc, argv);

    int seed = inf.readInt(1, 1000000000, "seed");
    int T = inf.readInt(1, 1000, "T");

    vector<int> X(T);
    for (int i = 0; i < T; i++)
        X[i] = inf.readInt(1, 1000000000, "X");

    rnd.setSeed(seed);

    // First Step:
    // 새 지문에서는 role이 가장 먼저 주어진다.
    cout << "dadas08" << endl;

    // N은 이제 참가자가 직접 출력한다.
    int N = ouf.readInt(1, 160, "N");

    vector<pair<int, int>> edges;
    vector<vector<int>> g(N);
    set<pair<int, int>> used;
    DSU dsu(N);

    for (int i = 0; i < N - 1; i++) {
        int u = ouf.readInt(1, N, "u") - 1;
        int v = ouf.readInt(1, N, "v") - 1;

        if (u == v)
            quitf(_wa, "edge %d is a loop", i + 1);

        pair<int, int> q = minmax(u, v);

        if (!used.insert(q).second)
            quitf(_wa, "edge %d is duplicated", i + 1);

        if (!dsu.unite(u, v))
            quitf(_wa, "the printed graph contains a cycle");

        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i < N; i++) {
        if (dsu.find(i) != dsu.find(0))
            quitf(_wa, "the printed graph is disconnected");
    }

    // 하나의 재번호화를 모든 테스트 케이스에 공통으로 사용한다.
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);

    for (int i = 0; i < N; i++)
        swap(p[i], p[rnd.next(i, N - 1)]);

    vector<int> order(N - 1);
    iota(order.begin(), order.end(), 0);

    for (int i = 0; i < N - 1; i++)
        swap(order[i], order[rnd.next(i, N - 2)]);

    // Second Step input 생성.
    // 새 지문: role -> N -> edges -> T -> colorings
    tout << "lunarlity\n";
    tout << N << '\n';

    for (int id : order) {
        int u = p[edges[id].first];
        int v = p[edges[id].second];

        if (rnd.next(0, 1))
            swap(u, v);

        tout << u + 1 << ' ' << v + 1 << '\n';
    }

    tout << T << '\n';

    // First Step에서 이제 T를 전달한다.
    cout << T << endl;

    for (int tc = 0; tc < T; tc++) {
        cout << X[tc] << endl;

        string s = ouf.readToken();

        if ((int)s.size() != N) {
            quitf(_wa,
                  "coloring %d has length %d instead of %d",
                  tc + 1, (int)s.size(), N);
        }

        for (char ch : s) {
            if (ch != 'W' && ch != 'B') {
                quitf(_wa,
                      "coloring %d contains a character other than W/B",
                      tc + 1);
            }
        }

        vector<int> color(N);
        vector<int> flip(N);

        for (int i = 0; i < N; i++)
            color[i] = (s[i] == 'B');

        if (tc % 6 == 1) {
            fill(flip.begin(), flip.end(), 1);
        } else if (tc % 6 == 2) {
            flip[rnd.next(0, N - 1)] = 1;
        } else if (tc % 6 == 3) {
            for (int i = 0; i < N; i++)
                flip[i] = i & 1;
        } else if (tc % 6 >= 4) {
            for (int i = 0; i < N; i++)
                flip[i] = rnd.next(0, 1);
        }

        for (int u = 0; u < N; u++) {
            if (!flip[u])
                continue;

            color[u] ^= 1;

            for (int v : g[u])
                color[v] ^= 1;
        }

        string result(N, 'W');

        for (int u = 0; u < N; u++) {
            if (color[u])
                result[p[u]] = 'B';
        }

        tout << result << '\n';
    }

    if (!ouf.seekEof())
        quitf(_pe, "extra tokens after the last coloring");

    quitf(_ok, "first invocation accepted");
}