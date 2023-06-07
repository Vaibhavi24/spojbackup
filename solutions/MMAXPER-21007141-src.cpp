#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll a[1000]={0};
ll x[1000], y[1000];
ll d[1001][2]={0};

ll ff(ll x[], ll y[], int n)
{
    for(int i=0;i<=n;i++)
        {
            d[i][1]=0;
            d[i][0]=0;
        }

   d[0][0] = x[0];
   d[0][1] = y[0];
   for(int i=1;i<n;i++)
    {
        d[i][0] = x[i] + max(d[i-1][0]+ abs(y[i]-y[i-1]), d[i-1][1]+ abs(y[i]-x[i-1]));

        d[i][1] = y[i] + max(d[i-1][0]+ abs(x[i]-y[i-1]), d[i-1][1]+ abs(x[i]-x[i-1]));
    }
/*
for(int i=0;i<=n;i++)
    cout<<d[i]<<" ";
cout<<endl;
*/

/*
5
5 2
8 3
10 1
7 14
2 5
*/
    ll ans = max(d[n-1][0], d[n-1][1]);
    return ans;
}

int main()
{
int n;
cin>>n;

for(int i=0;i<n;i++)
cin>>x[i]>>y[i];

cout<<ff(x, y, n)<<endl;
return 0;
}
