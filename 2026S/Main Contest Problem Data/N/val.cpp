#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);

    int T=inf.readInt(1,150,"T");
    inf.readEoln();

    long long sum=0;

    for(int tc=1;tc<=T;tc++){
        int N=inf.readInt(1,1000,format("N[%d]",tc));
        inf.readEoln();

        sum+=1LL*N*N;
        ensuref(sum<=1000000,
            "sum of N^2 exceeds 1000000: %lld after test case %d",
            sum,tc);
    }

    inf.readEof();
}