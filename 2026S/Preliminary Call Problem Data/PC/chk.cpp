#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int N = inf.readInt();
    string S = inf.readToken();
    string T = inf.readToken();

    vector<int> cntS(26), cntT(26);
    for (char c : S) cntS[c - 'A']++;
    for (char c : T) cntT[c - 'A']++;

    bool possible = true;
    if (cntS != cntT) possible = false;
    else if (cntS[2] == 0 && S != T) possible = false;

    string verdict = ouf.readToken();

    if (verdict == "NO") {
        if (possible) quitf(_wa, "answer is possible.");
        quitf(_ok, "Correct.");
    }

    if (verdict != "YES") quitf(_wa, "expected YES or NO.");
    if (!possible) quitf(_wa, "Answer is impossible.");

    int K = ouf.readInt(0, 1000000, "K");
    string cur = S;

    for (int i = 1; i <= K; i++) {
        int a = ouf.readInt(1, N, "a");
        int b = ouf.readInt(1, N, "b");
        a--; b--;
        if (a == b) quitf(_wa, "operation %d uses the same position.", i);
        if (cur[a] != 'C' && cur[b] != 'C') quitf(_wa, "operation %d does not contain C.", i);

        swap(cur[a], cur[b]);
    }

    if (cur != T) quitf(_wa, "result is not T.");
    quitf(_ok, "Correct. K = %d.", K);
}