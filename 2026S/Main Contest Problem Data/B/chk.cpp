#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);

    inf.readInt(1, 1000000000, "seed");
    int T = inf.readInt(1, 1000, "T");

    for (int tc = 1; tc <= T; tc++) {
        int expected = inf.readInt(1, 1000000000, "X");
        int found = ouf.readInt(1, 1000000000, "decoded X");
        if (found != expected)
            quitf(_wa, "test case %d: expected %d, found %d",
                  tc, expected, found);
    }

    if (!ouf.seekEof())
        quitf(_pe, "extra tokens after %d answers", T);

    quitf(_ok, "all %d integers were decoded correctly", T);
}
