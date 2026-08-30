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
    registerTestlibCmd(argc, argv);

    int seed = inf.readInt(1, 1'000'000'000, "seed");
    int T = inf.readInt(1, 1'000, "T");

    for (int tc = 0; tc < T; ++tc) {
        int N = inf.readInt(2, 200'000, "N");
        int M = inf.readInt(1, 200'000, "M");

        vector<pair<int, int>> edges(M);

        for (int i = 0; i < M; ++i) {
            int u = inf.readInt(1, N, "u") - 1;
            int v = inf.readInt(1, N, "v") - 1;
            edges[i] = {u, v};
        }

        // interactor와 완전히 같은 난수 생성
        mt19937_64 gen = makeRng(seed, tc);

        int deleted = (int)(gen() % (uint64_t)M);

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        shuffleBy(p, gen);

        int expectedU = p[edges[deleted].first] + 1;
        int expectedV = p[edges[deleted].second] + 1;

        int foundU = ouf.readInt(1, N, "u");
        int foundV = ouf.readInt(1, N, "v");

        if (foundU == foundV) {
            quitf(_wa,
                  "test case %d: the two endpoints must be different",
                  tc + 1);
        }

        pair<int, int> expected = minmax(expectedU, expectedV);
        pair<int, int> found = minmax(foundU, foundV);

        if (found != expected) {
            quitf(_wa,
                  "test case %d: expected (%d, %d), found (%d, %d)",
                  tc + 1,
                  expected.first, expected.second,
                  found.first, found.second);
        }
    }

    if (!ouf.seekEof())
        quitf(_pe, "extra tokens after %d answers", T);

    quitf(_ok, "all %d deleted edges were found", T);
}