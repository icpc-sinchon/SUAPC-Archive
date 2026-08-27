#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, S[303030], P[303030], A[303030];
vector<int> lnk[303030];

void dfs(int p, int x) {
    S[p]=1; for (int i : lnk[p]) if (i!=x) P[i]=p, dfs(i, p), S[p]+=S[i];
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    dfs(1, 0);
    for (int i=1; i<=N; i++) {
        vector<int> V;
        for (int j : lnk[i]) V.push_back(j==P[i]?N-S[i]:S[j]);
        sort(V.begin(), V.end()); reverse(V.begin(), V.end());
        for (int j=0; j<V.size(); j++) A[j]=max(A[j], V[j]);
    }
    for (int i=1; i<=N; i++) cout << A[i] << " ";

	return 0;
}