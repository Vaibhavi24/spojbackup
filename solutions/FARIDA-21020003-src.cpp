#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll a[10004]={0};
ll d[10004]={0};

ll f(int i, int n)
{
   if(i>=n)
        return 0;

   if(d[i]==0)
   {
       d[i] = max(a[i] + f(i+2, n), f(i+1, n));
   }

   return d[i];
}

int main()
{
    int t;
    cin>>t;
    int ct=0;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            d[i]=0;

        cout<<"Case "<<ct+1<<": "<<f(0, n)<<endl;
        ct++;
    }
    return 0;
}
