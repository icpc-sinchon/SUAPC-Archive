#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string R;
    cin >> R;

    if (R == "dadas08") {
        int T;
        cin >> T;

        while (T--) {
            int N, M;
            cin >> N >> M;

            vector<int> parity(N, 0);

            for (int i = 0; i < M; ++i) {
                int u, v;
                cin >> u >> v;
                --u;
                --v;

                parity[u] ^= 1;
                parity[v] ^= 1;
            }

            string s(N, '0');

            for (int i = 0; i < N; ++i)
                s[i] = char('0' + parity[i]);

            cout << s << endl;
        }
    } else if (R == "lunarlity") {
        int T;
        cin >> T;

        while (T--) {
            int N, M;
            cin >> N >> M;

            vector<int> parity(N, 0);

            for (int i = 0; i < M; ++i) {
                int u, v;
                cin >> u >> v;
                --u;
                --v;

                parity[u] ^= 1;
                parity[v] ^= 1;
            }

            string s;
            cin >> s;

            vector<int> bad;

            for (int i = 0; i < N; ++i) {
                if (parity[i] != s[i] - '0')
                    bad.push_back(i + 1);
            }

            cout << bad[0] << ' ' << bad[1] << endl;
        }
    }

    return 0;
}