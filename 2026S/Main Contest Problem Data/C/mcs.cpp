#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

ll N, A[200005];
vector<ll> V[200005];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> N;
    ll M = 0;
    for(ll i = 1; i <= N; i++){
        cin >> A[i];
        M = max(M, A[i] + A[i - 1]);
    }
    for(ll i = 1; i <= N; i++){
        if(i % 2 == 1){
            for(ll j = 1; j <= A[i]; j++){
                V[j].push_back(i);
            }
        } else {
            for(ll j = M - A[i] + 1; j <= M; j++){
                V[j].push_back(i);
            }
        }
    }
    cout << M << '\n';
    for(ll i = 1; i <= M; i++){
        cout << V[i].size() << ' ';
        for(auto e : V[i]){
            cout << e << ' ';
        }
        cout << '\n';
    }
}