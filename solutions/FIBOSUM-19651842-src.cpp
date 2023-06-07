#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll MOD=1000000007;

void multiply(ll a[2][2], ll b[2][2])
{
  ll temp[2][2]={{0,0},{0,0}};

  temp[0][0]=((a[0][0]*b[0][0])%MOD + (a[0][1]*b[1][0])%MOD)%MOD;
  temp[0][1]=((a[0][0]*b[0][1])%MOD + (a[0][1]*b[1][1])%MOD)%MOD;
  temp[1][0]=((a[1][0]*b[0][0])%MOD + (a[1][1]*b[1][0])%MOD)%MOD;
  temp[1][1]=((a[1][0]*b[0][1])%MOD + (a[1][1]*b[1][1])%MOD)%MOD;

   a[0][0]=temp[0][0];a[0][1]=temp[0][1];
   a[1][0]=temp[1][0];a[1][1]=temp[1][1];
}

void power(ll f[2][2],int n)
{
    ll m[2][2]={{1,1},{1,0}};
    if(n==1||n==0)
        return;

    power(f,n/2);
    multiply(f,f);

    if(n%2==1)
    {
        multiply(f,m);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ll fn[2][2]={{1,1},{1,0}};

        power(fn,n+1);
        ll sum=-(fn[0][1]-1)%MOD;
         ll fm[2][2]={{1,1},{1,0}};
        power(fm,m+2);
        sum+=(fm[0][1]-1)%MOD;
        if(sum<0)
            sum+=MOD;
        cout<<sum<<endl;
    }
    return 0;
}
