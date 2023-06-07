#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001]={0};

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char a[2001],b[2001];
        scanf("%s",a);scanf("%s",b);
        int i=0,la,lb;

        while(a[i]!='\0') i++;
        la=i;

        i=0;
        while(b[i]!='\0') i++;
        lb=i;

        for(int i=0;i<2001;i++)
            for(int j=0;j<2001;j++)
                dp[i][j]=0;

        for(int i=0;i<=la;i++)
            for(int j=0;j<=lb;j++)
            {
            if(i==0)//a empty string,insert all chars of b
            dp[i][j]=j;
            else if(j==0)
            dp[i][j]=i;
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
        cout<<dp[la][lb]<<endl;
    }
    return 0;
}
