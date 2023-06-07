#include<bits/stdc++.h>

using namespace std;

int a[2000][2000]={0};
int v[2000]={0};

int f(int i, int j, int v[], int n, int t)
{
if(a[i][j] == 0)
{
if(i==j)
a[i][j] = n*v[i];
else
a[i][j] = max(t*v[i] + f(i+1, j, v, n, t+1) , t*v[j] + f(i, j-1, v, n, t+1));
}

return a[i][j];
}

int main()
{
int n;
cin>>n;

for(int i=0;i<n;i++)
cin>>v[i];

cout<<f(0, n-1, v, n, 1)<<endl;
/*
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
}*/
return 0;
}
