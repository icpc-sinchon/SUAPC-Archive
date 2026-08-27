#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 100'000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 100'000, "M");
    inf.readEoln();
    for(int i=1;i<=N;i++)
    {
        inf.readInt(1, 20, "A_i");
        if(i<N) inf.readSpace();
        else inf.readEoln();
    }
    for(int i=1;i<=M;i++)
    {
        inf.readInt(1, 20, "B_i");
        if(i<M) inf.readSpace();
        else inf.readEoln();
    }
    for(int i=1;i<=N;i++)
    {
        inf.readInt(1, 20, "C_i");
        if(i<N) inf.readSpace();
        else inf.readEoln();
    }
    for(int i=1;i<=M;i++)
    {
        inf.readInt(1, 20, "D_i");
        if(i<M) inf.readSpace();
        else inf.readEoln();
    }

    int count = 0;
    int Q = inf.readInt(1,100'000,"Q");
    inf.readEoln();
    for(int i=1;i<=Q;i++)
    {
        int type = inf.readInt(1,5,"type");
        inf.readSpace();
        if(type==1)
        {
            int L1 = inf.readInt(1,N,"L1");
            inf.readSpace();
            int R1 = inf.readInt(1,N,"R1");
            inf.readSpace();
            int L2 = inf.readInt(1,M,"L2");
            inf.readSpace();
            int R2 = inf.readInt(1,M,"R2");
            inf.readEoln();

            ensure(L1<=R1);
            ensure(L2<=R2);
            count++;
        }
        else if(type==2)
        {
            inf.readInt(1,N,"ind");
            inf.readSpace();
            inf.readInt(1,20,"val");
            inf.readEoln();
        }
        else if(type==3)
        {
            inf.readInt(1,M,"ind");
            inf.readSpace();
            inf.readInt(1,20,"val");
            inf.readEoln();
        }
        else if(type==4)
        {
            inf.readInt(1,N,"ind");
            inf.readSpace();
            inf.readInt(1,20,"val");
            inf.readEoln();
        }
        else if(type==5)
        {
            inf.readInt(1,M,"ind");
            inf.readSpace();
            inf.readInt(1,20,"val");
            inf.readEoln();
        }
    }
    inf.readEof();
    
    ensure(count>=1);
}
