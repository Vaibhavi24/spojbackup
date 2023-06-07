#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll d[65][10]={0};
ll ff[65][10]={0};
int ith=1;

ll f(int i, int num)
{
    if(i==0)
        return 1;

    if(num<0)
        return 0;

    if(ff[i][num]!=ith)
    {
        ff[i][num] = ith;
        d[i][num]  = 0;

        d[i][num] += f(i, num-1) + f(i-1, num);
    }

    return d[i][num];
}

int main()
{
    int q;
    cin>>q;

    while(ith<=q)
    {
        int x;
        cin>>x;
        int n;
        cin>>n;

        cout<<x<<" ";
        ll ans = f(n, 9);
        //for(int i = 9; i>=0; i--)
        //ans += f(n, i);

        cout<<ans<<endl;

        ith++;
    }
    return 0;
}
