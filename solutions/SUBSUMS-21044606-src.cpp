#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll a[35]={0};
ll sum1[1<<17]={0};
ll sum2[1<<17]={0};

int left(ll a[], int n, ll b)
{
    int l = 0, r = n-1;

    while(l<=r)
    {
        int mid = r + (l-r)/2;
        if(a[mid] >= b)
            r = mid-1;
        else l= mid+1;
    }

    return l;
}

int right(ll a[], int n, ll b)
{
    int l = 0, r = n-1;

    while(l<=r)
    {
        int mid = r + (l-r)/2;
        if(a[mid] <= b)
            l = mid+1;
        else r= mid-1;
    }

    return r;
}

int bits(int num)
{
    int x=0;
    while(num)
    {
        x++;
        num/=2;
    }
    return x;
}

int main()
{
    int N;
    ll ans = 0;
    ll A, B;
    cin>>N>>A>>B;

    for(int i=0;i<N;i++)
        cin>>a[i];

    int sz1=1<<(N/2), sz2=1<<(N-N/2);
    for(int i=0; i< sz1;i++)
    {
        int nb = bits(i);
        for(int j=0;j<nb;j++)
            if(i & (1<<j))
            sum1[i] += a[j];

        if(sum1[i]>=A && sum1[i]<=B)
                ans++;
    }

    for(int i=0; i< sz2;i++)
    {
        int nb = bits(i);
        for(int j=0;j<nb;j++)
            if(i & (1<<j))
            sum2[i] += a[j+N/2];
    }

    sort(sum1, sum1 + sz1);
    for(int i=1;i< sz2;i++)
    {
        ll R = B - sum2[i];
        ll L = A - sum2[i];

        int r = right(sum1, sz1, R);
        int l = left (sum1, sz1, L);
//cout<<sum2[i]<<" "<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
        if(r<sz1 && l>=0 && r>=l)
        ans += (ll)(r-l+1);
    }

    cout<<ans<<endl;
/*
3 -2 10
1
-2
0
*/
    return 0;
}
