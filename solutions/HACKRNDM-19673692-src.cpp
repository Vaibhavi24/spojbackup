#include<bits/stdc++.h>

using namespace std;
 int a[100005];

bool f(int l, int r ,int x)
{
    while(l<=r)
    {
        int mid=(l+r)/2;

        if(x==a[mid])
            return true;
        if(x>a[mid])
            l=mid+1;
        else r=mid-1;
    }
    return false;
}

int ct_bin(map<int,int> freq, int n, int k)
{
   int ct=0;

   for(int i=0;i<n-1;i++)
   {
       int key=a[i]+k;
       if(f(i+1, n-1, key))
        ct+=freq[key];
   }
   return ct;
}

int main()
{
    int t;
   // cin>>t;
    //while(t--)
    {
        int n,k;
        cin>>n>>k;
       map<int,int> freq;
        for(int i=0;i<n;i++)
            {cin>>a[i];freq[a[i]]++;}
        sort(a,a+n);

        int ans=ct_bin(freq,n,k);
        cout<<ans<<endl;
    }
    return 0;
}
