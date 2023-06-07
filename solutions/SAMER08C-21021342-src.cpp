#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll d[100005]={0};
ll b[100005]={0};
ll t[100005]={0};
ll best[100005]={0};

ll frd(int i, vector<ll> a, int n, vector<ll> temp)
{
if(i>=n)
return 0;

if(temp[i] == 0)
{
    temp[i] = max(a[i]+ frd(i+2, a, n, temp), frd(i+1, a, n, temp));
}

return temp[i];
}

ll f(int i, vector<vector<ll> > a, int r)
{
if(i>=r)
    return 0;

if(d[i]==0)
{
    d[i] = max(best[i] + f(i+2, a, r), f(i+1, a, r));
}

return d[i];
}

int main()
{
    int m, n;
    while(1)
    {
        cin>>m>>n;
        if(m==0 && n==0)
            break;

        ll a[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            cin>>a[i][j];

        for(int i=0;i<m;i++)
        {
            t[0] = 0;
            t[1] = a[i][0];

            for(int j=2;j<=n;j++)
            t[j] = max(a[i][j-1] + t[j-2], t[j-1]);

            b[i] = t[n];
        }

        d[0] = 0;
        d[1] = b[0];

        for(int i=2;i<=m;i++)
        {
            d[i] = max(b[i-1] + d[i-2], d[i-1]);
        }

        cout<<d[m]<<endl;
    }

/**
        vector< vector<ll> > a;

        for(int i=0;i<m;i++)
        {
            vector<ll> v;
            ll x;
            for(int j=0;j<n;j++)
                {
                    cin>>x;
                    v.push_back(x);
                }
            a.push_back(v);
            d[i] = 0;
        }

        for(int i=0;i<m;i++)
        {
            vector<ll> temp(n);
            best[i] = frd(0, a[i], n, temp);
        }
        cout<<f(0, a, m)<<endl;
    }
    **/
    return 0;
}
