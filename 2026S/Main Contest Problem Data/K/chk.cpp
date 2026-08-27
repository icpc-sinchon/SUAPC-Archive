#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int N = inf.readInt();

    ll k = ouf.readLong(1LL, 1000000LL, "K");
    ll a = ouf.readLong(1LL, 2LL * N, "A");
    ll b = ouf.readLong(1LL, 2LL * N, "B");

    if (!ouf.seekEof()) {
        quitf(_wa, "Extra output found");
    }

    if (k <= 0) quitf(_wa, "k must be positive, but k = %lld", k);

    if (a <= 0 || b <= 0) quitf(_wa, "Both numbers must be positive, but a = %lld, b = %lld", a, b);

    ll ansK = 1;
    while (ansK * ansK + ansK < N) ansK++;

    if (k > ansK) {
        quitf(_wa, "k must be %lld, but contestant printed %lld", ansK, k);
    }

    vector<unsigned char> reach(N + 1, false);

    for (ll x = -k; x <= k; x++) {
        ll absX = (x < 0 ? -x : x);
        ll rem = k - absX;

        for (ll y = -rem; y <= rem; y++) {
            __int128 pos = static_cast<__int128>(x) * a + static_cast<__int128>(y) * b;
            if (1 <= pos && pos <= N) reach[static_cast<int>(pos)] = true;
        }
    }

    for (int value = 1; value <= N; value++) {
        if (!reach[value]) quitf(_wa, "%d cannot be reached in at most %lld operations using %lld and %lld",   value, k, a, b);
    }

    quitf(_ok, "All integers from 1 to %d are reachable in at most %lld operations",  N, k);
}