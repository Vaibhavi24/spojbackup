#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll c[10000]={0};
ll p[10000]={0};
int visited[10001]={0};
ll d[10001][10001]={0};

ll f(int i, int j, int n)
{
if(j<0 || j>=n)
    return INT_MAX;
if(i == 0)
return p[0];

if(d[i][j] == 0)
{
    d[i][j] = min(f(i-1, j-1, n) + p[i], f(i-1, j+1, n) + c[i]);
}

return d[i][j];
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        {
            cin>>c[i]>>p[i];
        }

    cout<<f(n-1, 0, n)<<endl;
/*
       for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
        }*/
    return 0;
}
