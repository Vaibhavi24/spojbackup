#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll d[10000][10000]={0};

ll f(ll a[], int i, ll sum, int n)
{
if(i >= n)
    return 0;

if(sum < 0)
    return -1;

if(d[sum][i]==0)
{
    ll aa = 0;

    if(sum>=a[i])
    aa=f(a, i+2, sum-a[i], n) + a[i];

    ll bb =0;
    bb=f(a, i+1, sum, n);

    d[sum][i]=max(aa, bb);
}

return d[sum][i];
}

int main()
{
    int t;
    cin>>t;

    int i=0;
    while(t--)
    {
        ll n, s;
        cin>>n>>s;

        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<=s;i++)
        {
            for(int j=0;j<=n;j++)
                d[i][j]=0;
        }

        cout<<"Scenario #"<<i+1<<": "<<f(a, 0, s, n)<<endl;
        i++;
    }
    return 0;
}

