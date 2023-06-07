#include<bits/stdc++.h>

using namespace std;
int ith=1;

vector<int> adj[100005];
int d[100005][2] = {0};
int ff[100005][2]= {0};
int visited[100005]={0};

int f(int s, int m, int par)
{
        if(ff[s][m] != ith)
        {
        ff[s][m] = ith;
        d[s][m] = m;

        for(int i=0;i<adj[s].size();i++)
        if(adj[s][i] != par)
        {
            if(m==0)
            d[s][0] += f(adj[s][i], 1, s);
            else if(m==1)
            d[s][1] += min(f(adj[s][i], 1, s), f(adj[s][i], 0, s));
        }
        }
    return d[s][m];
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = min(f(1, 0, -1), f(1, 1, -1));

       if(n==1)
        ans=1;

    cout<<ans<<endl;

    return 0;
}
