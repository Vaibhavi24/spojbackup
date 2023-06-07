#include<bits/stdc++.h>

using namespace std;

int v[5]={0};
int d[5][100005]={0};

bool f(int i, int n, int val, int Kp, int V)
{
    if(val == V)
        return true;

    if(i==n || val > V)
        return false;

    if(d[i][val] == -1)
    {
        d[i][val] = 0;
        for(int k=1;k<=Kp;k++)
        {
            d[i][val] = d[i][val] | f(i+1, n, val + k*v[i], k, V);
            if(d[i][val]==true)
                break;
        }
    }

    return d[i][val];
}

int main()
{
    int x;
    cin>>x;
    int k;
    cin>>k;

    for(int i=0;i<k;i++)
        cin>>v[i];

    for(int i=0;i<k;i++)
    {
        for(int s=0;s<=x;s++)
            d[i][s]=-1;
    }

    bool sol = f(0, k, 0, (x/v[0]), x);
    if(sol)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
