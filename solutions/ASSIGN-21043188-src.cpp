#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll d[1<<20]={0};

int setb(int num)
{
    int x=0;
    while(num)
    {
        if(num & 1)
        x++;
        num/=2;
    }
    return x;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int m[21][21]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        }

        int all = (1<<n)-1;
        for(int i=0;i<=all;i++)
        {
            d[i]=0;
        }
        d[0] = 1;

        for(int j=0;j<=all;j++)
        {
            int x=setb(j)+1;

            if(x<=n)
            {
                for(int k=0;k<n;k++)
            {
                if(m[x-1][k]==1 && (!(j & (1<<k))))
                d[j|(1<<k)] += d[j];
            }
            }
        }
       // for(int i=0;i<=all;i++)
        //    cout<<d[i]<<" ";
        cout<<d[all]<<endl;
    }
    return 0;
}
