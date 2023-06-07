#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int ith=1;
ll ff[100005]={0};
ll d[100005]={0};
ll a[100005]={0};

ll f(int i, int n)
{
    if(i>=n)
    return 0;

    if(ff[i]!=ith)
    {
    ff[i] = ith;
    d[i] = max(a[i] + f(i+2, n), max(a[i]+a[i+1]*(i+1<n?1:0) + f(i+4, n), a[i]+a[i+1]*(i+1<n?1:0)+a[i+2]*(i+2<n?1:0) + f(i+6, n)));
    }

    return d[i];
}

int main()
{
    int t;
    scanf("%d",&t);

    while(ith<=t)
    {
        int n;
        scanf("%d", &n);

        for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);

        printf("%lld", f(0,n));
        printf("\n");
        ith++;
    }
    return 0;
}
