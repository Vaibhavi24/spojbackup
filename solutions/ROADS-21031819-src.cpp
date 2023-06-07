#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

class road
{
    public:
    int d;
    ll l;
    ll t;
    road(int dd, ll L, ll tt):d(dd), l(L), t(tt){}
};

bool operator<(const road& r1, const road& r2)
{
    return (r1.l > r2.l);
}

ll ff[101][10001]={0};
ll dd[101][10001] ={0};
vector<road> adj[101];
bool visited[101] = {0};
int ith = 1;

ll f(int s, int e, ll toll)
{
    if(toll<0)
    return INT_MAX;

    if(s==e)
    return 0;

    if(ff[s][toll]!=ith)
    {
        dd[s][toll] = INT_MAX;
        ff[s][toll] = ith;

    for(int i=0;i<adj[s].size();i++)
    {
        road curr = adj[s][i];

        if(!visited[curr.d] && toll>=curr.t)
        {
            visited[curr.d]=1;
            dd[s][toll] = min(curr.l + f(curr.d, e, toll-curr.t), dd[s][toll]);
            visited[curr.d]=0;
        }
    }
    }

    return dd[s][toll];
}

ll djk(int N, int K)
{
    priority_queue<road, vector<road>, less<vector<road>::value_type> > pq;

    road s(1, 0, 0);
    pq.push(s);

    for(int i=1;i<=N;i++)
    {
        for(int k=0;k<=K;k++)
            dd[i][k]=INT_MAX;
    }

    dd[1][0] = 0;

    while(!pq.empty())
    {
     road curr = pq.top();
     pq.pop();

     int L = curr.l;
     int u = curr.d;
     int k = curr.t;

     if(dd[u][k] != L)
        continue;

     if(u == N)
        break;

     for(int i=0;i<adj[u].size();i++)
     {
         road ext = adj[u][i];
         int v = ext.d;
         int ln= ext.l;
         int c = ext.t;

         if(k+c <= K && (dd[v][k+c] > dd[u][k] + ln))
         {
             dd[v][k+c] = dd[u][k] + ln;

             road temp(v, dd[v][k+c], k+c);
             pq.push(temp);
         }
     }
    }

    ll ans = INT_MAX;
    for(int k=0;k<=K;k++)
    ans = min(ans, dd[N][k]);

    if(ans == INT_MAX)
        ans = -1;

    return ans;
}
/**
1
1
3
2
1 2 2 1
2 3 5 0

1
0
2
5
1 2 5 0
1 2 4 0
1 2 3 0
1 2 4 1
2 1 0 0

1
2
2
5
1 2 3 3
1 2 3 4
1 2 5 1
1 1 8 0
1 2 3 2

1
3
3
9
1 1 4 0
1 2 5 0
2 1 4 0
1 2 1 1
1 2 3 2
2 3 5 5
2 3 5 2
2 3 3 2
1 3 10 2
**/
int main()
{
    int tt;
    cin>>tt;

    while(ith<=tt)
    {
        ll k, n, r;
        cin>>k>>n>>r;

        for(int i=1;i<=n;i++)
        {
        if(!adj[i].empty())
        adj[i].clear();

        visited[i]=0;
        }

        ll s, d, l, t;
        for(int i=0;i<r;i++)
            {
                cin>>s>>d>>l>>t;
                road temp(d, l, t);

                if(s!=d)
                adj[s].push_back(temp);
            }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
                cout<<adj[i][j].d<<" ";
            cout<<endl;
        }*/
        /*
        visited[1]=1;
        ll ans = f(1, n, k);
        visited[1]=0;
        */

        ll ans = djk(n, k);
        cout<<ans<<endl;

        ith++;
    }
    return 0;
}
