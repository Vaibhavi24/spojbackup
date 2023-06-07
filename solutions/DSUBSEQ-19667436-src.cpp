#include<bits/stdc++.h>

using namespace std;

long long int dss[100005]={0};
const int MOD=1000000007;

int distinct_subseq(string a)
{
    int n=a.length();

    for(int i=0;i<=n;i++)
            dss[i]=0;

    dss[0]=1;

    int last[125]={0};
    for(int i=0;i<125;i++)
    last[i]=-1;

    for(int i=1;i<=n;i++)
    {
        dss[i]= (2*dss[i-1])%MOD;

        int last_occur=last[(int) a[i-1]];
        if(last_occur!=-1)
        {
            dss[i]-=dss[last_occur];
            dss[i]+=(dss[i]<0)?MOD:0;
        }

        last[(int)a[i-1]]=i-1;
        dss[i]=dss[i]%MOD;
    }

    return dss[n]%MOD;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string a;
    cin>>a;
    cout<<distinct_subseq(a)<<endl;
    }
    return 0;
}
