#include<bits/stdc++.h>

using namespace std;

int a[101][101]={0};
int d[101][101]={0};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    {
                        d[i][j]=0;
                        continue;
                    }

                d[i][j] = a[i-1][j-1] + max(i>=1? d[i-1][j]:0, max( i>=1 && j>=1 ? d[i-1][j-1] : 0, i>=1 && j+1<=m ? d[i-1][j+1] : 0));
            }
        }

        int ans = 0;
        for(int j=1;j<=m;j++)
        ans = max(ans, d[n][j]);

        cout<<ans<<endl;
    }
    return 0;
}
