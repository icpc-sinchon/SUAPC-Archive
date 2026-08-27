#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using lll = __int128_t;
using P = pair<ll,ll>;
ll pw (lll a,lll b) {
    lll r = 1;
    for (; b; b >>= 1, a *= a) if (b & 1) r *= a;
    return (ll)r;
}
void solve() {
    ll n, m, k, q; cin >> n >> m >> q >> k;
    vector<vector<P>> G(n+1);
    vector<array<ll,3>> E(m);
    for (auto &[u, v, w] : E) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    vector<ll> D(n+1), V(n+1);
    auto dfs = [&] (auto &&Self,int v,int b=-1)-> void {
        V[v] = 1;
        for (auto [nx, w] : G[v]) if (!V[nx]) {
            D[nx] = D[v] + w;
            Self(Self, nx, v);
        }
    };
    dfs(dfs, 1);

    ll g = 0;
    for (auto [u, v, w] : E) {
        g = gcd(g, abs(D[u] - D[v] + w));
    }
    auto fac = [&] (vector<ll> &A,ll tmp) {
        if (!tmp) return;
        while (~tmp & 1) {
            A.push_back(2);
            tmp >>= 1;
        }
        for (ll i = 3; i * i <= tmp; i += 2) {
            while (tmp % i == 0) {
                A.push_back(i);
                tmp /= i;
            }
        }
        if (tmp > 1) A.push_back(tmp);
    };
    vector<ll> FG, F, A;
    fac(FG, g); 
    int sz = FG.size();
    for (int s = 0, e = 0; s < sz; s = e) {
        while (e < sz && FG[s] == FG[e]) e++;
        F.push_back(FG[s]);
        A.push_back(e-s); 
    }
    sz = F.size(); 
    vector<ll> B(sz), S;
    vector<P> res;
    auto cal = [&] (auto &&Self,int i,ll h)-> void {
        if (i >= sz) {
            S.clear();
            for (int s = 0; s < sz; s++) {
                if (A[s] > B[s]) S.push_back(pw(F[s], B[s]+1));
            }
            int j = S.size();
            ll ans = 0;
            for (int s = 0; s < (1 << j); s++) {
                ll d = (__builtin_popcount(s) & 1 ? -1 : 1), r = 1;
                for (int e = 0; e < j; e++) if (1 << e & s) r *= S[e];
                ans += d * (k / r);
            }
            res.push_back({h, ans});
            return;
        }
        for (int s = 0; s <= A[i]; s++) {
            B[i] = s;
            Self(Self, i+1, h * pw(F[i], s));
        }
    };
    cal(cal, 0, 1);
    sort(all(res));
    while (q--) {
        int u, v; cin >> u >> v;
        if (!g) {
            cout << k << "\n";
            continue;
        }
        ll h = gcd(g, abs(D[u] - D[v]));
        cout << res[lower_bound(all(res), P(h, 0)) - res.begin()].second << "\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}