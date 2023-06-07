#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define MOD 100000007

ll d[1005][1024]={0};
ll ff[1005][1024]={0};

ll a[1005]={0};
ll b[1005]={0};
int v[1005]={0};

int u=1;

ll F(int i, int n, int sum)
{
    for(int s=0;s<=sum;s++)
        d[i][s]=0;

    d[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int s=0;s<=sum;s++)
        d[i][s] = (d[i-1][s]+d[i-1][s^a[i-1]])%MOD;
    }

    return d[n][sum];
}

ll f(int n, int m)
{
    ll tot = F(n, n, 1023);

    ll ans = 0;
    for(int i=0;i<=1023;i++)
    {
        if(!v[i])
        ans = (ans+d[n][i])%MOD;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(u<=t)
    {
        int n, m;
        cin>>n>>m;

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<=1023;i++)
            v[i]=0;

        for(int j=0;j<m;j++)
            {
                cin>>b[j];
                v[b[j]]=1;
            }

        cout<<"Case "<<u<<": "<<f(n, m)<<endl;
        u++;
    }
    return 0;
}
