#include <bits/stdc++.h>
#define MAX 1'000'005
using namespace std;
int n, arr[MAX], wh[MAX], dp[MAX];
vector<int> v[MAX];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        wh[i]=v[arr[i]].size();
        v[arr[i]].push_back(i);
    }
    int pt=1;
    for(int i=1;i<=n;i++)
    {
        while(pt<=wh[i]+1&&dp[pt-1]<v[arr[i]][wh[i]-pt+1])
            dp[pt]=i, pt++;
    }
    cout<<pt-1<<"\n";
}
