#include<bits/stdc++.h>
using namespace std;

int dp[4001][4001]={0};

int main()
{
        char a[4001],b[4001];

        int i=0,j=0,la,lb;
        int k;
        scanf("%s %s %i",a,b,&k);
        while(a[i]!='\0') i++;
        la=i;

        i=0;
        while(b[i]!='\0') i++;
        lb=i;

        i=0;
        for(int i=0;i<4001;i++)
            for(int j=0;j<4001;j++)
                dp[i][j]=0;

        for( i=0;i<=la;i++)
            for( j=0;j<=lb;j++)
            {
            if(i==0)//a empty string,insert all spaces
            dp[i][j]=k*j;
            else if(j==0)
            dp[i][j]=k*i;
            else
            dp[i][j]=min((dp[i-1][j-1]+abs((int) a[i-1]-b[j-1])), min(dp[i][j-1], dp[i-1][j])+k);

            }

            /*(int i=0;i<=la;i++)
                {for(int j=0;j<=lb;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;}*/

        printf("%i\n", dp[la][lb]);
    return 0;
}

