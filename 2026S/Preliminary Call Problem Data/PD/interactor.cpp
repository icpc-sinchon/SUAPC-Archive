#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

static mt19937_64 makeRng(int seed, int tc) {
    uint64_t x = (uint64_t)seed;
    x ^= 0x9e3779b97f4a7c15ULL * (uint64_t)(tc + 1);
    return mt19937_64(splitmix64(x));
}

template <class T>
static void shuffleBy(vector<T> &a, mt19937_64 &gen) {
    for (int i = 0; i < (int)a.size(); ++i) {
        int j = i + (int)(gen() % (uint64_t)(a.size() - i));
        swap(a[i], a[j]);
    }
}

int main(int argc, char **argv) {
    registerInteraction(argc, argv);

    int seed = inf.readInt(1, 1'000'000'000, "seed");
    int T = inf.readInt(1, 1'000, "T");

    cout << "dadas08" << endl;
    cout << T << endl;

    // Second Step input
    tout << "lunarlity\n";
    tout << T << '\n';

    for (int tc = 0; tc < T; ++tc) {
        int N = inf.readInt(2, 200'000, "N");
        int M = inf.readInt(1, 200'000, "M");

        vector<pair<int, int>> edges(M);

        for (int i = 0; i < M; ++i) {
            int u = inf.readInt(1, N, "u") - 1;
            int v = inf.readInt(1, N, "v") - 1;
            edges[i] = {u, v};
        }

        cout << N << ' ' << M << '\n';

        for (auto [u, v] : edges)
            cout << u + 1 << ' ' << v + 1 << '\n';

        cout.flush();

        string s = ouf.readToken("[01]+", "written numbers");

        if ((int)s.size() != N) {
            quitf(_wa,
                  "test case %d: written string has length %d instead of %d",
                  tc + 1, (int)s.size(), N);
        }

        mt19937_64 gen = makeRng(seed, tc);

        // 삭제할 간선
        int deleted = (int)(gen() % (uint64_t)M);

        // p[old] = new
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        shuffleBy(p, gen);

        // 남은 간선 출력 순서
        vector<int> order;
        order.reserve(M - 1);

        for (int i = 0; i < M; ++i) {
            if (i != deleted)
                order.push_back(i);
        }

        shuffleBy(order, gen);

        // 정점 번호 변경에 맞춰 문자열도 이동
        string moved(N, '0');

        for (int old = 0; old < N; ++old)
            moved[p[old]] = s[old];

        tout << N << ' ' << M - 1 << '\n';

        for (int id : order) {
            int u = p[edges[id].first];
            int v = p[edges[id].second];

            if (gen() & 1ULL)
                swap(u, v);

            tout << u + 1 << ' ' << v + 1 << '\n';
        }

        tout << moved << '\n';
    }

    if (!ouf.seekEof())
        quitf(_pe, "extra tokens after the last written string");

    quitf(_ok, "first invocation accepted");
}