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
vector<pair<int,int>>ans;
vector<pair<int,int>> 
ins6={
    {1,5},{2,4},{3,5},{1,1},{2,2},
    {4,4},{3,1},{4,2},{5,1},{5,5}
},
ins8={
    {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},
    {5,3},{6,2},{7,1},{5,1},{7,3},{7,5},{5,7},
    {3,1},{3,5},{2,6},{1,7},{3,7}
},
ins10={
    {1,1},{2,2},{3,1},
    {1,5},{2,4},{2,6},
    {4,2},{1,7},{2,8},
    {5,1},{5,3},{6,4},
    {3,9},{4,8},{7,3},
    {5,9},{8,2},{5,7},
    {6,6},{4,4},{7,7},
    {9,1},{8,4},{4,6},
    {7,1},{1,9},{8,8},
    {7,9},{9,9},{9,5},{9,7}
},
init2={{1,1}},
init4={{1,1},{2,2},{3,3},{1,3},{3,1}},
init6={
    {1,1},{2,2},{3,1},{4,2},{5,1},
    {5,3},{4,4},{5,5},{3,5},{2,4},{1,5}
},
init8={
    {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},
    {3,5},{2,6},{1,7},{1,5},{3,7},
    {5,3},{6,2},{7,1},{5,1},{7,3},
    {1,3},{3,1},{5,7},{7,5}
},
init10={
    {1,1},{2,2},{3,1},{4,2},{5,1},{6,2},{7,1},{8,2},{9,1},
    {9,3},{8,4},{9,5},
    {1,3},{2,4},{1,5},{2,6},{1,7},{2,8},{1,9},
    {3,9},{4,8},{5,9},{6,8},{7,9},{8,8},{9,9},{9,7},
    {7,5},{6,4},{5,5},{4,4},{4,6}
};
void h(int n){
    ans.pb({n,n});
    ans.pb({n+1,n+1});
    ans.pb({n+2,n+2});
    for(int i=n-1;i>0;i--){
        ans.pb({n+1+(i+1)%2,i});
        ans.pb({i,n+1+(i+1)%2});
    }
}
void g(int n, int off, bool rot, vector<pair<int,int>>&ins){
    if(rot)for(auto &x:ins)ans.pb({n-x.first+off,n-x.second+off});
    else for(auto &x:ins)ans.pb({x.first+off,x.second+off});
}
void f(int n, int off, bool rot, bool init){
    if(n<=10){
        if(init){
            if(n==2)g(n,off,rot,init2);
            if(n==4)g(n,off,rot,init4);
            if(n==6)g(n,off,rot,init6);
            if(n==8)g(n,off,rot,init8);
            if(n==10)g(n,off,rot,init10);
            return;
        }
        if(n==6)g(n,off,rot,ins6);
        if(n==8)g(n,off,rot,ins8);
        if(n==10)g(n,off,rot,ins10);
        return;
    } int i,j;
    for(i=1;i<n;i++){
        if(rot) ans.pb({n-i+off,n-(1+(i-1)%2)+off});
        else ans.pb({i+off,1+(i-1)%2+off});
    } for(i=3;i<=n-7;i++){
        if(rot) ans.pb({n-(n-2+i%2)+off,n-i+off});
        else ans.pb({n-2+i%2+off,i+off});
    } int st=5; if(init)st=3;
    for(i=st;i<n;i++){
        if(rot) ans.pb({n-(1+(i-1)%2)+off,n-i+off});
        else ans.pb({1+(i-1)%2+off,i+off});
    } for(i=3;i<n;i++){
        if(rot) ans.pb({n-i+off,n-(n-2+i%2)+off});
        else ans.pb({i+off,n-2+i%2+off});
    } if(rot){
        if(!init) ans.pb({n-2+off,n-4+off});
        ans.pb({1+off,3+off});
        ans.pb({2+off,4+off});
        ans.pb({1+off,5+off});
        ans.pb({3+off,5+off});
        ans.pb({3+off,7+off});
    } else{
        if(!init) ans.pb({2+off,4+off});
        ans.pb({n-1+off,n-3+off});
        ans.pb({n-2+off,n-4+off});
        ans.pb({n-1+off,n-5+off});
        ans.pb({n-3+off,n-5+off});
        ans.pb({n-3+off,n-7+off});
    } f(n-6,off+3,!rot,0);
}
int a[1005][1005];
void solve(){
    int i,j,n; cin>>n;
    if(n==1||n==3){cout<<"0\n"; return;}
    bool odd=0; if(n%2==1)odd=1,n-=3;
    f(n,0,0,1); if(odd)h(n);
    cout<<ans.size()<<endl;
    for(auto &x:ans)cout<<x.fi<<" "<<x.se<<endl;
    ans.clear();
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
