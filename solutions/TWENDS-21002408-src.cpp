#include<bits/stdc++.h>

using namespace std;

int d[1001][1001]={0};

int f(int a[], int i, int j, int n)
{
if(i>=n)
    return 0;
if(i>=j)
    return 0;

if(d[i][j]==0)
{
    int aa = 0;// = f(a, i+1, j-1) + a[i];
    int b  = 0;//= f(a, i+1, j-1) + a[j];

    if(a[i+1]>=a[j])
        aa = f(a, i+2, j, n) + a[i];
    else aa= f(a, i+1, j-1, n) + a[i];

    if(a[i]>=a[j-1])
        b = f(a, i+1, j-1, n) + a[j];
    else b= f(a, i, j-2, n) + a[j];

    d[i][j] = max(aa, b);
}

return d[i][j];
}

int main()
{
int n;
int i=0;

while(1)
{
    cin>>n;
    if(n==0)
        break;

    int a[n];
    int tot = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            d[i][j]=0;
    }

    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            tot += a[i];
        }

    int s = f(a, 0, n-1, n);//cout<<s<<endl;
    int diff = 2*s - tot;
    cout<<"In game "<<i+1<<", the greedy strategy might lose by as many as "<<diff<<" points."<<endl;

    i++;
}

return 0;
}
