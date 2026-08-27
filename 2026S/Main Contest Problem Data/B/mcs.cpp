#include <bits/stdc++.h>
using namespace std;

const int N = 160;
const int K = 32;

int c(int i)  { return 5 * i; }
int a(int i)  { return 5 * i + 1; }
int aa(int i) { return 5 * i + 2; }
int b(int i)  { return 5 * i + 3; }
int bb(int i) { return 5 * i + 4; }

vector<pair<int, int>> make_tree() {
    vector<pair<int, int>> e;

    for (int i = 0; i + 1 < K; i++)
        e.push_back({c(i), c(i + 1)});

    for (int i = 0; i < K; i++) {
        e.push_back({c(i), a(i)});
        e.push_back({a(i), aa(i)});
        e.push_back({c(i), b(i)});
        e.push_back({b(i), bb(i)});
    }

    return e;
}

void dadas08() {
    // 새 형식: 먼저 N을 출력한다.
    cout << N << '\n';

    vector<pair<int, int>> e = make_tree();

    for (auto [u, v] : e)
        cout << u + 1 << ' ' << v + 1 << '\n';

    cout.flush();

    int T;
    cin >> T;

    while (T--) {
        int X;
        cin >> X;

        string s(N, 'W');

        // 양 끝 marker: 0, 1
        s[a(K - 1)] = 'B';

        // 가운데 30개 gadget에 X 저장
        for (int i = 0; i < 30; i++) {
            if ((X >> i) & 1)
                s[a(i + 1)] = 'B';
        }

        cout << s << endl;
    }
}

void lunarlity() {
    // 새 형식에서는 role 다음에 N이 들어온다.
    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> is_center(n);

    for (int i = 0; i < n; i++)
        is_center[i] = (int)g[i].size() >= 3;

    int st = -1;

    for (int u = 0; u < n; u++) {
        if (!is_center[u])
            continue;

        int cnt = 0;

        for (int v : g[u])
            cnt += is_center[v];

        if (cnt == 1) {
            st = u;
            break;
        }
    }

    vector<int> path;

    int prv = -1;
    int u = st;

    while (u != -1) {
        path.push_back(u);

        int nxt = -1;

        for (int v : g[u]) {
            if (is_center[v] && v != prv)
                nxt = v;
        }

        prv = u;
        u = nxt;
    }

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        vector<int> z(K);

        for (int i = 0; i < K; i++) {
            int u = path[i];

            for (int v : g[u]) {
                if (is_center[v])
                    continue;

                z[i] ^= (s[v] == 'B');

                for (int w : g[v]) {
                    if (w != u)
                        z[i] ^= (s[w] == 'B');
                }
            }
        }

        if (z[0] == 1)
            reverse(z.begin(), z.end());

        int X = 0;

        for (int i = 0; i < 30; i++)
            X |= z[i + 1] << i;

        cout << X << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string role;
    cin >> role;

    if (role == "dadas08")
        dadas08();
    else
        lunarlity();
}