#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int lcs[1001][1001]={0};
int lis[1001]={0},lds[1001]={0},lbs[1001]={0};

int findlcs(int a[],int b[],int n,int k)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        if(i==0||j==0)
        lcs[i][j]=0;
        else if(a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
        else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
    return lcs[n][n];
}

int longBitonic(int a[],int b[],int s[],int n,int k)
{

      int maxs=0,maxbitonic=0;

    findlcs(a,s,n,k);
    lis[0]=0;
    for(int i=1;i<=n;i++)
        lis[i]=lcs[i][k];

    findlcs(b,s,n,k);
    lds[0]=0;
    for(int i=1;i<=n;i++)
        lds[i]=lcs[n-i+1][k];
//cout<<lis[2]<<" "<<lds[2]<<a[2]<<endl;
    lbs[0]=0;
    for(int i=1;i<=n;i++)
        {
            lbs[i]=lis[i]+lds[i]-1;
            if(lbs[i]>maxbitonic)
                maxbitonic=lbs[i];
        }
    return maxbitonic;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,k=0;
    cin>>n;
    int arr[1001]={0}, sorted[1001]={0}, rev[1001]={0};
    bool visited[1001]={0};
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        if(!visited[arr[i]])
        sorted[k++]=arr[i];
        rev[n-1-i]=arr[i];
        visited[arr[i]]=true;
        }

    sort(sorted,sorted+k);
    int len=longBitonic(arr,rev,sorted,n,k);
    cout<<len<<endl;
    }
    return 0;
}


