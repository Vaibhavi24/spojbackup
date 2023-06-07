#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll d[500][500]={0};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, K;
        cin>>n>>K;

        for(int i=0;i<=n;i++)
            for(int k=0;k<=K;k++)
            d[i][k]=0;

        d[0][0]=1;
        d[1][0]=1;

        for(int i=2;i<=n;i++)
        {
            int l = (i-1)*(i-1-1)/2;
            for(int k=0;k<=l;k++)
            {
               for(int j=0;j<=i-1;j++)
                {
                    if(k+j==0)
                    d[i][k+j] =1;
                    else
                    d[i][k+j] += d[i-1][k];
                }
            }
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=K;j++)
            cout<<d[i][j]<<" ";
            cout<<endl;
        }
        */
        cout<<d[n][K]<<endl;
    }
    return 0;
}
