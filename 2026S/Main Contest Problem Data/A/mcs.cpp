#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n; string s; cin >> n >> s; int ans = 0;
    for(int i = 1; i < n; i++) ans += (s[i-1] == 'C' && isdigit(s[i]));
    cout << ans;
}