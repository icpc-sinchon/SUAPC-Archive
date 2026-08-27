#include <bits/stdc++.h>
using namespace std;

namespace {
constexpr int OK = 0;
constexpr int WA = 1;
constexpr int FAIL = 3;

[[noreturn]] void quit(int code, const string& message) {
    cerr << message << '\n';
    exit(code);
}

bool readLongLong(istream& in, long long& value) {
    in >> value;
    return static_cast<bool>(in);
}
}  // namespace

// Polygon checker protocol:
// argv[1] = input file, argv[2] = participant output, argv[3] = jury answer.
// The jury answer is intentionally unused because optimality is computed from input.
int main(int argc, char* argv[]) {
    if (argc < 4) quit(FAIL, "checker: expected input, output, and answer file paths");

    ifstream inf(argv[1]);
    ifstream ouf(argv[2]);
    if (!inf) quit(FAIL, "checker: cannot open input file");
    if (!ouf) quit(WA, "cannot open participant output");

    int n;
    if (!(inf >> n) || n < 1 || n > 200000) {
        quit(FAIL, "checker: malformed input N");
    }

    vector<int> a(n + 2, 0);
    long long requiredSelections = 0;
    for (int i = 1; i <= n; ++i) {
        if (!(inf >> a[i]) || a[i] < 0 || a[i] > 200000) {
            quit(FAIL, "checker: malformed input A_i");
        }
        requiredSelections += a[i];
    }

    int optimum = 0;
    for (int i = 0; i <= n; ++i) {
        optimum = max(optimum, a[i] + a[i + 1]);
    }

    long long k64;
    if (!readLongLong(ouf, k64)) quit(WA, "missing K");
    if (k64 < 0 || k64 > 200000) quit(WA, "K is outside [0, 200000]");
    int k = static_cast<int>(k64);

    if (k != optimum) {
        quit(WA, "K is not minimum: expected " + to_string(optimum) +
                     ", found " + to_string(k));
    }

    vector<int> count(n + 1, 0);
    vector<int> seenAt(n + 2, 0);
    long long totalSelections = 0;

    for (int t = 1; t <= k; ++t) {
        long long s64;
        if (!readLongLong(ouf, s64)) {
            quit(WA, "missing size of operation " + to_string(t));
        }
        if (s64 < 0 || s64 > (n + 1LL) / 2) {
            quit(WA, "invalid size in operation " + to_string(t));
        }
        if (totalSelections + s64 > requiredSelections) {
            quit(WA, "too many total box selections");
        }
        totalSelections += s64;

        for (long long j = 0; j < s64; ++j) {
            long long x64;
            if (!readLongLong(ouf, x64)) {
                quit(WA, "missing box index in operation " + to_string(t));
            }
            if (x64 < 1 || x64 > n) {
                quit(WA, "box index outside [1, N] in operation " + to_string(t));
            }
            int x = static_cast<int>(x64);

            if (seenAt[x] == t) {
                quit(WA, "duplicate box in operation " + to_string(t));
            }
            if (seenAt[x - 1] == t || seenAt[x + 1] == t) {
                quit(WA, "adjacent boxes selected in operation " + to_string(t));
            }

            seenAt[x] = t;
            ++count[x];
            if (count[x] > a[x]) {
                quit(WA, "box " + to_string(x) + " receives too many balls");
            }
        }
    }

    string extra;
    if (ouf >> extra) quit(WA, "extra token after the last operation: " + extra);

    if (totalSelections != requiredSelections) {
        quit(WA, "wrong total number of selected boxes");
    }
    for (int i = 1; i <= n; ++i) {
        if (count[i] != a[i]) {
            quit(WA, "box " + to_string(i) + " should receive " +
                         to_string(a[i]) + " balls, but receives " +
                         to_string(count[i]));
        }
    }

    quit(OK, "ok: minimum K = " + to_string(k));
}
