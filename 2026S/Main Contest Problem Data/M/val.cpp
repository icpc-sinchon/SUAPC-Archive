#include <stdio.h>
#include "testlib.h"

int next[300010],color[300010],check[300010];
int find(int k)
{
    if(k==next[k]) return k;
    else return next[k] = find(next[k]);
}

int direX[5]={1,0,-1,0}, direY[5]={0,1,0,-1};
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1,400,"n");
    inf.readSpace();
    int m = inf.readInt(1,400,"m");
    inf.readEoln();

    for(int i=0;i<n*m;i++) next[i] = i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int val = inf.readInt(1,n*m,"color_ij");
            color[(i-1)*m+(j-1)] = val;
            if(j<m) inf.readSpace();
            else inf.readEoln();
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int s = i+direX[k], t = j+direY[k];
                if(1<=s&&s<=n&&1<=t&&t<=m);
                else continue;
                int val1 = (i-1)*m + (j-1);
                int val2 = (s-1)*m + (t-1);
                if(color[val1]==color[val2])
                {
                    next[find(val1)] = find(val2);
                }
            }
        }
    }
    for(int i=0;i<n*m;i++) check[color[find(i)]] = find(i);
    for(int i=0;i<n*m;i++)
    {
        ensuref(find(i) == find(check[color[find(i)]]), "pieces are not connected");
    }

    int q = inf.readInt(1,n*m,"q");
    inf.readEoln();
    for(int i=1;i<=q;i++)
    {
        inf.readInt(1,n,"row");
        inf.readSpace();
        inf.readInt(1,m,"col");
        inf.readEoln();
    }
    inf.readEof();
}