#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int U[MAX], V[MAX], D[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, ans;

    vector<int> ans_res, arr;
    queue<int> q;

    cin >> N >> M, ans = N + 1;
    for (int i = 1; i <= M; i++) {
        cin >> U[i] >> V[i];
        adj[U[i]].push_back(i), adj[V[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        fill(D + 1, D + N + 1, -1);
        q.push(i), D[i] = 0, arr.clear();

        while (!q.empty()) {
            X = q.front(), q.pop();
            for (int j : adj[X]) {
                Y = X ^ U[j] ^ V[j];
                if (D[Y] == -1) {
                    q.push(Y), D[Y] = D[X] + 1;
                    arr.push_back(j);
                }
            }
        }

        if (*max_element(D + 1, D + N + 1) < ans) {
            ans = *max_element(D + 1, D + N + 1);
            ans_res = arr;
        }
    }

    for (int i : ans_res)
        cout << i << ' ';
    cout << '\n';

    return 0;
}