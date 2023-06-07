#include<bits/stdc++.h>

using namespace std;

int a[1001]={0}, b[1001]={0};
int d[1001][1001]={0};
int sz[1001]={0};

int f(int n, int m)
{/*
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        d[i][j]=0;
        */

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
         {
             if(i==0 || j==0)
             {
                 d[i][j]=0;
                 continue;
             }

             if(a[i-1]==b[j-1])
             d[i][j] = 1 + d[i-1][j-1];
             else if(d[i-1][j]>=d[i][j-1])
             d[i][j] = d[i-1][j];
             else d[i][j] = d[i][j-1];
         }
    return d[n][m];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n=0;
        int i=0;
        int ans = 0;

        while(1)
        {
            int x;
            cin>>x;
            if(x==0)
                break;
            a[n++] = x;
        }

        while(1)
        {
        int m = 0;
        while(1)
        {
            int x;
            cin>>x;
            if(x==0)
                break;
            b[m++] = x;
        }
        if(m==0)
        break;

        ans = max(ans, f(n, m));
        }

        cout<<ans<<endl;
    }
    return 0;
}
