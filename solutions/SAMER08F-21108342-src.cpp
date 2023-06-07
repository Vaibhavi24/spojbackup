#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll d[101]={0};

int main()
{
    int n;

    while(1)
    {
    cin>>n;

    if(n==0)
        break;

    d[0]=0;
    for(ll i=1;i<=n;i++)
    {
        d[i] = i*i + d[i-1];
    }

    cout<<d[n]<<endl;
    }
    cout<<endl;
    return 0;
}
