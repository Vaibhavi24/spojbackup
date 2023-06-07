#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll t[1001]={0};

void m(void)
{
    t[0] = 1;
    t[1] = 1;
    t[2] = 5;
    t[3] = 11;

    for(int i=4;i<=1000;i++)
    {
        t[i] = t[i-1] + 5*t[i-2] + t[i-3] - t[i-4];
    }
}

int main()
{
    m();
    int c;
    cin>>c;

    int ith=1;

    while(ith<=c)
    {
    int n;
    cin>>n;

    if(n==-1)
    break;

    cout<<ith<<" "<<t[n]<<endl;
    ith++;
    }

    return 0;
}
