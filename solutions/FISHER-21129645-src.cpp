#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<int> adj[101];

ll T[101][101]={0};
ll D[101][101]={0};
ll d[101][10004]={0};

void f(int root, int ttime, ll dist, int N, int K)
{
    d[root][ttime] = min(dist, d[root][ttime]);

    for(int i = 1; i<=N; i++)
    {
        int v = i;
        if(v==root || ttime + T[root][v] > K)
            continue;

        if(d[v][ttime + T[root][v]] > d[root][ttime] + D[root][v])
        {
            f(v, ttime+T[root][v], d[root][ttime] + D[root][v], N, K);
        }
    }
}

void F(int n, int ttime)
{
    for(int i=0;i<=n;i++)
    {
        for(int t=0;t<=ttime;t++)
            d[i][t] = INT_MAX;
    }

    f(1, 0, 0, n, ttime);

    ll rmin = INT_MAX, tmin = INT_MAX;
    for(int t=0;t<=ttime;t++)
    {
        if(d[n][t] < rmin)
        {
            rmin = d[n][t];
            tmin = t;
        }
    }

    if(rmin == INT_MAX)
    cout<<"-1"<<endl;
    else
    cout<<rmin<<" "<<tmin<<endl;
}

int main()
{
    ll n, k;
    while(1)
    {
        cin>>n>>k;

        if(n==0 && k==0)
            break;

        for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            cin>>T[i][j];

        for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            cin>>D[i][j];

        F(n, k);
    }
    return 0;
}
