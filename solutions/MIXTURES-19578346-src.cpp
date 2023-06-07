#include<stdio.h>
#include<limits.h>
#include<iostream>

using namespace std;

int main()
{
        int n;
        while(scanf("%d",&n)>0) //scanning EOF(end of file) gives value -1
        {
int a[101]={0},v[101][101]={0},mul[101][101]={0};
            int i=0;
        for(;i<n;i++)
            scanf("%d",&a[i]);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
            v[i][j]=0;
        else v[i][j]=INT_MAX;

        mul[i][j]=a[j];
            }

        for(int L=2;L<=n;L++)
            {

                for(int i=0;i<n-L+1;i++)
        {
            int j=i+L-1;
            int mink=n+1;
            for(int k=i;k<j;k++)
            {
                int temp=v[i][k]+v[k+1][j]+mul[i][k]*mul[k+1][j];
                if(temp<v[i][j])
                {
                    v[i][j]=temp;
                    mink=k;
                }
            }
            //cout<<i<<" "<<mink<<" "<<j<<" "<<v[i][j]<<endl;
      mul[i][j]=(mul[i][mink]+mul[mink+1][j])%100;
        }
            }
        printf("%d\n",v[0][n-1]);
    }
    return 0;
}
