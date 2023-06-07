#include<bits/stdc++.h>

using namespace std;
 int lcs[1002][1002]={0};

int findlcs(char a[],char b[],int la,int lb)
{
    for(int i=0;i<=la;i++)
        for(int j=0;j<=lb;j++)
    {
        if(i==0||j==0)
            lcs[i][j]=0;
        else if(a[i-1]==b[j-1])
            lcs[i][j]=lcs[i-1][j-1]+1;
        else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
    }
    return lcs[la][lb];
}

int main()
{
    while(1)
    {
    char a[1002]={0},b[1002]={0};
    cin>>a;
    if(a[0]=='#')
        break;
    cin>>b;
    int la=0,lb=0,i;
    for(i=0;a[i]!='\0';i++);
        la=i;
    for(i=0;b[i]!='\0';i++);
        lb=i;
    int l=findlcs(a,b,la,lb);
    //cout<<la<<" "<<lb<<" "<<l<<endl;
    int cost=(la-l)*15 +(lb-l)*30;
    cout<<cost<<endl;
    }
    return 0;
}
