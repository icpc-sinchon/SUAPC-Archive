#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S1, E1, S2, E2;
    cin >> S1 >> E1;
    cin >> S2 >> E2;

    static bool seen[1001][1001];

    for (int m1 = S1; m1 <= E1; ++m1) {
        for (int m2 = S2; m2 <= E2; ++m2) {
            int g = std::gcd(m1, m2);
            int p = m1 / g;
            int q = m2 / g;

            if (seen[p][q]) {
                cout << "NO\n";
                return 0;
            }
            seen[p][q] = true;
        }
    }

    cout << "YES\n";
    return 0;
}