#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define elif else if
int n,m,k,q;
void solve(){
    int i,j,l,r; cin>>n;
    map<pair<int,int>,bool>mp;
    int x=0,t=3;
    vector<int>v; while(n){
        v.pb(n%6); n/=6;
    } reverse(v.begin(),v.end());
    mp[{0,0}]=mp[{0,-1}]=mp[{0,-2}]=mp[{-1,0}]=mp[{-2,0}]=0;
    mp[{-3,0}] =v[0]>=5;
    mp[{-2,-1}]=v[0]>=4;
    mp[{-1,-2}]=v[0]>=3;
    mp[{0,-3}] =v[0]>=2;
    mp[{1,-2}] =v[0]>=1;
    n=v.size();
    for(i=1;i<n;i++){
        for(j=0;j<9;j++)mp[{x+j/3,x+j%3}]=0;
        for(j=1;j<=i;j++)mp[{x+2+j,x}]=mp[{x,x+2+j}]=0;
        for(j=x-1;j>=-i-2;j--)mp[{x+2+i,j}]=mp[{j,x+2+i}]=0;
        mp[{x+i+1,-i-2}]=v[i]>=5;
        mp[{x+i+2,-i-3}]=v[i]>=4;
        mp[{x+i+3,-i-2}]=v[i]>=3;
        mp[{-i-2,x+i+1}]=v[i]>=2;
        mp[{-i-3,x+i+2}]=v[i]>=1;
        x+=2; t+=4;
    } cout<<mp.size()<<endl;
    for(auto[i,j]:mp)cout<<i.fi<<' '<<i.se<<' '<<(int)j<<endl;
    cout<<t<<' '<<x<<' '<<x<<endl;
}
signed main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // solve();
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
