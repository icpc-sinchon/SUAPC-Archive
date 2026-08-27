#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);

    int T=inf.readInt();

    for(int tc=1;tc<=T;tc++){
        int n=inf.readInt();

        long long M=ouf.readLong();
        long long maxM=(1LL*n*n-1)/3;

        if(M<0||M>maxM){
            quitf(_wa,
                "test case %d: M = %lld is out of range [0, %lld]",
                tc,M,maxM);
        }

        vector<vector<unsigned char>> a(
            n+1,vector<unsigned char>(n+1,0)
        );

        a[1][1]=1;
        long long planted=1;

        for(long long step=1;step<=M;step++){
            long long x=ouf.readLong();
            long long y=ouf.readLong();

            if(x<1||x>=n||y<1||y>=n){
                quitf(_wa,
                    "test case %d, operation %lld: "
                    "(%lld, %lld) is not a valid top-left corner",
                    tc,step,x,y);
            }

            int cnt=
                a[x][y]+
                a[x+1][y]+
                a[x][y+1]+
                a[x+1][y+1];

            if(cnt!=1){
                quitf(_wa,
                    "test case %d, operation %lld at (%lld, %lld): "
                    "2x2 contains %d planted cells, expected exactly 1",
                    tc,step,x,y,cnt);
            }

            a[x][y]=1;
            a[x+1][y]=1;
            a[x][y+1]=1;
            a[x+1][y+1]=1;

            planted+=3;
        }

        long long blank=1LL*n*n-planted;

        if(blank>10){
            quitf(_wa,
                "test case %d: %lld cells remain empty, maximum allowed is 10",
                tc,blank);
        }
    }

    if(!ouf.seekEof())
        quitf(_wa,"extra output after all test cases");

    quitf(_ok,"valid construction for all %d test cases",T);
}