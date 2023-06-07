#include<bits/stdc++.h>

using namespace std;

int d[1001][1001][2]={0};
int k[1001][1001]={0};
//int visited[1001][1001]={0};
//int ith=1;

int f(string a, string b, int n, int m, int K)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j]=0;
                continue;
            }

            if(a[i-1]==b[j-1])
            k[i][j]=k[i-1][j-1]+1;
            else k[i][j]=0;
        }
    }

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                d[i][j][0] = 0;
                d[i][j][1] = 0;
                continue;
            }

            d[i][j][1] = max(d[i-1][j][1], d[i][j-1][1]);
            d[i][j][0] = d[i][j][1];

            if(a[i-1]==b[j-1])
            {
                d[i][j][0] = max(d[i][j][0], 1 + d[i-1][j-1][0]);

                if(k[i][j]>=K)
                d[i][j][1] = max(d[i][j][1], K +d[i-K][j-K][0]);
            }
        }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        cout<<dir[i][j]<<" ";
        cout<<endl;
    }*/
    return d[n][m][1];
}
//conservatives breather
/*
void print(string a, string b, int i, int j, int &k, int &kmax)
{
    if(visited[i][j] == ith)
        return;

    visited[i][j]=ith;

    if(i>0 && j>0)
    {
        if(dir[i][j]=='a')
        {
            k++;
            kmax = max(kmax, k);

            print(a, b, i-1, j-1, k, kmax);
        }
        else if(dir[i][j] == 'u')
            {
                k=0;
                print(a, b, i-1, j, k, kmax);
            }
        else
        {
            k=0;
            print(a, b, i, j-1, k, kmax);
        }
    }
}

int all(string a, string b, int n, int m, int K)
{
int ans = 0;
for(int i=n;i>=0;i--)
{
    for(int j=m;j>=0;j--)
    if(visited[i][j]!=ith)
    {
        int k=0, kmax=0;
        print(a, b, i, j, k, kmax);
        if(kmax >= K)
        ans = max(ans, d[i][j]);
    }
}

return ans;
}
*/
int main()
{
    int k;
    while(1)
    {
        cin>>k;

        if(k==0)
            break;
        string a, b;
        cin>>a>>b;

        int n= a.length(), m = b.length();
        int l = f(a, b, n, m, k);
       // int len = all(a, b, n, m, k);
        cout<<l<<endl;
//        ith++;
    }
    return 0;
}
