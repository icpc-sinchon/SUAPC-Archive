#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 123456789
#define MIN -123456789

struct str{
    int value[20];
    str()
    {
        for(int i=0;i<20;i++) value[i] = MIN;
        value[0] = 0;
    }
    str(int cost, int val)
    {
        for(int i=0;i<20;i++) value[i] = MIN;
        value[0] = 0;
        value[cost] = val;
    }
};

str op(str A, str B)
{
    str ans;
    for(int i=0;i<20;i++)
    {
        for(int j=0;i+j<20;j++)
        {
            ans.value[i+j] = std::max(ans.value[i+j],A.value[i]+B.value[j]);
        }
    }
    return ans;
}

struct segTree1{
    str value[400010];
    void setValue(int ind, int cost, int val, int l=1, int r=100000, int v=1)
    {
        if(l==r) value[v] = str(cost,val);
        else
        {
            int h = (l+r)/2;
            if(ind<=h) setValue(ind,cost,val,l,h,2*v);
            else setValue(ind,cost,val,h+1,r,2*v+1);
            value[v] = op(value[2*v],value[2*v+1]);
        }
    }
    str getValue(int L, int R, int l=1, int r=100000, int v=1)
    {
        if(L<=l&&r<=R) return value[v];
        else if(r<L) return str();
        else if(R<l) return str();
        else
        {
            int h = (l+r)/2;
            str A = getValue(L,R,l,h,2*v);
            str B = getValue(L,R,h+1,r,2*v+1);
            return op(A,B);
        }
    }
}T1;

struct segTree2{
    int value[400010];
    void setValue(int ind, int val, int l=1, int r=100000, int v=1)
    {
        if(l==r) value[v] = val;
        else
        {
            int h = (l+r)/2;
            if(ind<=h) setValue(ind,val,l,h,2*v);
            else setValue(ind,val,h+1,r,2*v+1);
            value[v] = value[2*v]+value[2*v+1];
        }
    }

    int getSum(int L, int R, int l=1, int r=100000, int v=1)
    {
        if(L<=l&&r<=R) return value[v];
        else if(r<L) return 0;
        else if(R<l) return 0;
        else
        {
            int h = (l+r)/2;
            int s1 = getSum(L,R,l,h,2*v);
            int s2 = getSum(L,R,h+1,r,2*v+1);
            return s1+s2;
        }
    }
}T0,T2[20],T3;

int A[100010],B[100010],C[100010],D[100010];
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++) scanf("%d",&A[i]);
    for(int i=1;i<=b;i++) scanf("%d",&B[i]);
    for(int i=1;i<=a;i++) scanf("%d",&C[i]);
    for(int i=1;i<=b;i++) scanf("%d",&D[i]);

    for(int i=1;i<=a;i++) T0.setValue(i,A[i]);
    for(int i=1;i<=a;i++) T1.setValue(i,C[i],A[i]);
    for(int i=1;i<=b;i++) for(int j=0;j<20;j++) T2[j].setValue(i,std::min(B[i],j*D[i]));
    for(int i=1;i<=b;i++) T3.setValue(i,B[i]);

    int c;
    scanf("%d",&c);
    while(c--)
    {
        int d;
        scanf("%d",&d);
        if(d==1)
        {
            int e,f,g,h;
            scanf("%d%d%d%d",&e,&f,&g,&h);
            int base = T0.getSum(e,f);
            str P = T1.getValue(e,f);
            int ans = T3.getSum(g,h);
            for(int j=0;j<20;j++)
            {
                int val = base - P.value[j] + T2[j].getSum(g,h);
                ans = std::min(ans,val);
            }
            printf("%d\n",ans);
        }
        else if(d==2)
        {
            int e,f;
            scanf("%d%d",&e,&f);
            A[e] = f;
            T0.setValue(e,A[e]);
            T1.setValue(e,C[e],A[e]);
        }
        else if(d==3)
        {
            int e,f;
            scanf("%d%d",&e,&f);
            B[e] = f;
            for(int j=0;j<20;j++) T2[j].setValue(e,std::min(B[e],j*D[e]));
            T3.setValue(e,B[e]);
        }
        else if(d==4)
        {
            int e,f;
            scanf("%d%d",&e,&f);
            C[e] = f;
            T1.setValue(e,C[e],A[e]);
        }
        else if(d==5)
        {
            int e,f;
            scanf("%d%d",&e,&f);
            D[e] = f;
            for(int j=0;j<20;j++) T2[j].setValue(e,std::min(B[e],j*D[e]));
        }
    }
}