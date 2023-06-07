#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int marked[8000]={0};
ll sp2[501]={0};
int sz=0;

void seive(void)
{
    sp2[0] = 2;
    sz=1;

    for(int i=2;i<=7994;i++)
    {
        if(!marked[i])
        {
            for(int j=2*i;j<=7994;j += i)
            marked[j]=1;

            if(i%4 ==1)
            sp2[sz++]=i;
        }
    }
}

ll f(int num, int k)
{
    ll d[num+1];

    for(int i=0;i<=num;i++)
        d[i]=0;
    d[0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=num;j++)
            if(j>=i)
            d[j] += d[j-i];
    }
/*
     for(int i=1;i<=num;i++)
        cout<<d[i]<<" ";
     cout<<endl;
*/
    return d[num];
}

int main()
{
    seive();

    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<f(sp2[n-1], k)<<endl;
    }
    return 0;
}
