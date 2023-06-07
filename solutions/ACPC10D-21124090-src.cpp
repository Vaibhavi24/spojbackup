#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll ff[100005][3]={0};
ll d[100005][3] ={0};
ll a[100005][3] = {0};

int ith = 1;

ll f(int i, int j, int n)
{
    for(int i=0;i<n;i++)
      {
          d[i][0]=INT_MAX;
          d[i][1]=INT_MAX;
          d[i][2]=INT_MAX;
      }

    d[0][1] = a[0][1];
    d[0][2] = a[0][1]+a[0][2];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            d[i][j] = a[i][j]+ min(d[i-1][j], d[i-1][j+1]);
            else if(j==1)
            d[i][j] = a[i][j]+ min(min(d[i][j-1], d[i-1][j-1]), min(d[i-1][j], d[i-1][j+1]));
            else if(j == 2)
            d[i][j] = a[i][j]+ min(d[i][j-1], min(d[i-1][j-1], d[i-1][j]));
        }
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }*/

    return d[n-1][1];
}

int main()
{
    int n;

    while(1)
    {
        cin>>n;

        if(n == 0)
        break;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
                cin>>a[i][j];
        }

        cout<<ith<<". "<<f(0, 1, n)<<endl;

        ith++;
    }
    return 0;
}
