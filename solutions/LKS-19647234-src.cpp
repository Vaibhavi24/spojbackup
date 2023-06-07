#include<bits/stdc++.h>

using namespace std;

int kp[2][2000006]={0};
int v[505],wt[505];

int main()
{
    int k,n;
    cin>>k>>n;
    for(int i=0;i<n;i++)
        cin>>v[i]>>wt[i];

    for(int i=0;i<=n;i++)
        for(int w=0;w<=k;w++)
    {
        if(i==0||w==0)
            kp[i%2][w]=0;
        else if (w>=wt[i-1])
        kp[i%2][w]=max(kp[(i-1)%2][w],(kp[(i-1)%2][w-wt[i-1]]+ v[i-1]));
        else kp[i%2][w]=kp[(i-1)%2][w];
    }

    cout<<kp[n%2][k]<<endl;
    return 0;
}
