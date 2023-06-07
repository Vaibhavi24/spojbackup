#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;

vector<ll> num[64];
ll a[100005] = {0};
ll diag[100005]={0};
int sz=0;

int nbits(ll x)
{
int ct=0;
while(x>0)
{
    x=x>>1;
    ct++;
}
return ct;
}

ll f(int n)
{
    int maxk=0;
  for(int i=0;i<n;i++)
  {
      int k = nbits(a[i]);
      maxk = max(maxk, k);
      num[k].push_back(a[i]);
  }

  for(int k = 63; k>0; k--)
  {
      if(num[k].size())
      {
      diag[sz++] = num[k][0];

      for(int i = 1;i<num[k].size();i++)
      {
          ll X = num[k][0]^num[k][i];
          int newbits = nbits(X);
          num[newbits].push_back(X);
      }
      }
  }

  ll ans = 0;
  for(int i=0;i<sz;i++)
    ans = max(ans, ans^diag[i]);

  return ans;
}

int main()
{//ll s=1152921504606846975;cout<<s;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<f(n)<<endl;

    return 0;
}
