#include<bits/stdc++.h>

using namespace std;

int main()
{
while(1)
{
int w, n;
cin>>w>>n;

if(n==0 && w==0)
    break;

int d[101][501]={0};
int v[101]={0};
int c[101]={0};

for(int i=0;i<n;i++)
cin>>c[i]>>v[i];

int sum=0;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=w;j++)
{
d[i][j] = d[i-1][j];

if(j>=c[i-1])
d[i][j] = max(d[i][j], d[i-1][j-c[i-1]]+v[i-1]);
}
}

for(int j=w;j>=1;j--)
if(d[n][j]!=d[n][j-1])
{
    sum = j;
    break;
}

cout<<sum<<" "<<d[n][w]<<endl;
}
return 0;
}
