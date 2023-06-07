#include<stdio.h>
#include<iostream>

using namespace std;
typedef unsigned long long int ll;

ll tot[10004]={0};ll primes[10004]={0};int k=0;

void simpleseive(void)
{
    bool visited[10004]={0};

    for(ll i=2;i*i<=10000;i++)
    {
        for(ll j=2*i;j<=10000;j+=i)
                visited[j]=true;
    }

    for(int i=2;i<=10000;i++)
        if(!visited[i])
        {
            tot[i]=i-1;
        primes[k++]=i;
        }
//cout<<"LL"<<endl;
        for(int j=2;j<=10000;j++)
        for(int i=0;primes[i]<j&&i<k;i++)
        if(j%primes[i]==0)
        {tot[j]=tot[j]-tot[j]/primes[i];}
}

int main()
{
    int t;
    cin>>t;
    for(ll i=1;i<=10000;i++)
        {tot[i]=i;}
    simpleseive();

    for(ll i=2;i<=10000;i++)
        {tot[i]=tot[i-1]+tot[i];}

    while(t--)
    {
        int n;
        cin>>n;
        ll h=0;
        h=tot[n]*tot[n];
        cout<<h<<endl;
    }
    return 0;
}

