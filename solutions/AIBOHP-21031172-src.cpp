#include<bits/stdc++.h>

using namespace std;
int ff[6101][6101]={0};
int d[6101][6101]={0};
int ith=1;

int f(int n, int m, string a, string b)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            d[i][j]=0;
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                {
                    d[i][j]=0;
                    continue;
                }

            if(a[i-1]==b[j-1])
                d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }

    return d[n][m];
}

int main()
{
    int t;
    cin>>t;

    while(ith<=t)
    {
        string a;
        cin>>a;

        int n = a.length();

        string b;
        for(int i=n-1;i>=0;i--)
            b += a[i];

        int common = f(n, n, a, b);
        cout<<n-common<<endl;

        ith++;
    }
    return 0;
}
