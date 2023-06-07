#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
ll pts[100005][6]={0};

ll mnht(ll pt[100005][6], int kth, int idx, int d)
{
    ll dist=0;

    for(int i=0;i<d;i++)
    {
        dist+=abs(pt[kth][i]-pt[idx][i]);
    }

    return dist;
}
   /*
   10
   -70 -64 -6 -56 64 61 -57 16 48 -98
   */
ll max_cmb(ll cmbn[6], ll pt[100005][6], int n, int d)
{
    ll pk=0;ll idx=0;

   for(int i=0;i<n;i++)
   {
       ll val=0;

       for(int j=0;j<d;j++)
       {
           val+=(1-2*cmbn[j])*pt[i][j];
       }

       if(val>pk)
       {
           pk=val;
           idx=i;
       }
   }

   return idx;
}

int main()
{
   int n, d;
   cin>>n>>d;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<d;j++)
        cin>>pts[i][j];
   }

   ll pk[2<<d];

   for(int j=0;j< 1<<(d);j++)
   {
       ll cmbn[6]={0};
       for(int dig=0;dig< d; dig++)
       {
           if(j & 1<<dig)
             cmbn[dig]=1;
          // cout<<cmbn[dig]<<" ";
       }
//cout<<endl;
       pk[j]=max_cmb(cmbn, pts, n, d);
   }

   ll maxd=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j< 1<<(d);j++)
       maxd=max(maxd, mnht(pts, i, pk[j], d));
   }

   cout<<maxd<<endl;
   return 0;
}
