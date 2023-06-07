#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll ff[3][2000][2000]={0};
ll d[3][2000][2000]={0};
int ith=1;

ll f(int i, int H, int A)
{
    if(H<=0 || A<=0)
        return 0;

    if(ff[i][H][A] != ith)
    {
        ff[i][H][A]=ith;

        if(i==0)
        d[i][H][A] = 1+max(f(2, H-20, A+5), f(1, H-5, A-10));
        else if(i==1)
        d[i][H][A] = 1+max(f(0, H+3, A+2), f(2, H-20, A+5));
        else if(i==2)
        d[i][H][A] = 1+max(f(1, H-5, A-10), f(0, H+3, A+2));
    }

    return d[i][H][A];
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int H, A;
        cin>>H>>A;

        ll ans = max(f(0, H+3, A+2), max(f(1, H-5, A-10), f(2, H-20, A+5)));
        cout<<ans<<endl;

        ith++;
    }
    return 0;
}
