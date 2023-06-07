#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll arr[501]={0};

ll f(ll p[], ll w[], ll s, int i, int n)
{
    if(s==0)
    return 0;

    if(s<0)
    return INT_MAX;

    if(i==n)
    return INT_MAX;

    if(arr[i]==-1)
    {
        ll a = INT_MAX, b=INT_MAX, c=INT_MAX;
        if(s>=w[i])
            a=f(p, w, s-w[i], i, n) + p[i] ;
        if(i<n && s>=w[i])
            b = f(p, w, s-w[i], i+1, n) + p[i];

        c = f(p, w, s, i+1, n);


cout<<a<<" "<<b<<" "<<c<<endl;
        arr[i] = min(min(a, b), c);
    }
    return arr[i];
}

ll dd(ll p[], ll w[], ll s, int  n)
{
    ll d[s+1];

    for(int i=0;i<=s;i++)
    {
        d[i]=INT_MAX;
    }

    d[0]=0;
    for(int i=1;i<=s;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=w[j])
                d[i] = min(d[i], d[i-w[j]]+p[j]);
        }
    }

    return d[s];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll e, ff;
        cin>>e>>ff;

        ll s = ff-e;
        int n;
        cin>>n;

        ll p[500]={0}, w[500]={0};
        for(int i=0;i<n;i++)
            cin>>p[i]>>w[i];

        for(int i=0;i<n;i++)
            arr[i]=-1;

       ll ans = dd(p, w, s, n);
       if(ans<INT_MAX)
       cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;
       else cout<<"This is impossible."<<endl;
    }
    return 0;
}
