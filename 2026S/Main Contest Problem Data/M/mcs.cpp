#include <stdio.h>

int x[510][510];
int up[510][510],down[510][510],left[510][510],right[510][510];
int ansU[510][510],ansD[510][510],ansL[510][510],ansR[510][510];

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(x[i][j]==x[i-1][j]) up[i][j] = 1;
            if(x[i][j]==x[i+1][j]) down[i][j] = 1;
            if(x[i][j]==x[i][j-1]) left[i][j] = 1;
            if(x[i][j]==x[i][j+1]) right[i][j] = 1;
        }
    }

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            up[i][j] += up[i][j-1];
            down[i][j] += down[i][j-1];
            left[i][j] += left[i][j-1];
            right[i][j] += right[i][j-1];
        }
    }
    for(int j=1;j<=b;j++)
    {
        for(int i=1;i<=a;i++)
        {
            up[i][j] += up[i-1][j];
            down[i][j] += down[i-1][j];
            left[i][j] += left[i-1][j];
            right[i][j] += right[i-1][j];
        }
    }

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            ansU[i][j] = ansD[i][j] = i;
            ansL[i][j] = ansR[i][j] = j;
        }
    }

    int count = 800;
    while(count--)
    {
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                int U = ansU[i][j];
                int L = ansL[i][j];
                int D = ansD[i][j];
                int R = ansR[i][j];
                if(up[U][R]-up[U][L-1]-up[U-1][R]+up[U-1][L-1]>=1) U--;
                if(down[D][R]-down[D][L-1]-down[D-1][R]+down[D-1][L-1]>=1) D++;
                if(left[D][L]-left[U-1][L]-left[D][L-1]+left[U-1][L-1]>=1) L--;
                if(right[D][R]-right[U-1][R]-right[D][R-1]+right[U-1][R-1]>=1) R++;
                ansU[i][j] = U;
                ansL[i][j] = L;
                ansD[i][j] = D;
                ansR[i][j] = R;
            }
        }
    }

    int c;
    scanf("%d",&c);
    while(c--)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        printf("%d %d %d %d\n",ansU[s][t],ansL[s][t],ansD[s][t],ansR[s][t]);
    }
}