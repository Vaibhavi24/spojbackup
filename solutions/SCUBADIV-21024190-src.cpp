#include<bits/stdc++.h>

using namespace std;
typedef long long int  ll;

ll d[22][80][1001]={0};
int fl[22][80][1001]={0};

int wt[1001]={0};
int og[1001]={0};
int ng[1001]={0};
int ith=0;

ll f(int o, int nt, int i, int n)
{
    if(o==0 && nt==0)
        return 0;

    if(i>=n && (o>0 || nt>0))
        return INT_MAX;

if(fl[o][nt][i] != ith)
{
     int a = o-og[i];
     if(a<0)
     a=0;

     int b = nt-ng[i];
     if(b<0)
     b=0;

    d[o][nt][i] = min(wt[i] + f(a, b, i+1, n), f(o, nt, i+1, n));
    fl[o][nt][i] = ith;
}

return d[o][nt][i];
}

int main()
{
    int t;
    cin>>t;

    for(ith=1;ith<=t;ith++)
    {
        int o, nt;
        cin>>o>>nt;

        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        cin>>og[i]>>ng[i]>>wt[i];

        cout<<f(o, nt, 0, n)<<endl;
    }
    return 0;
}
