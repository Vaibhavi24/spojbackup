#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll t[31]={0};
ll f[31]={0};

void m(void)
{
    int n = 30;
    t[0]=1;
    f[0]=0;

    for(int i=1;i<=n;i++)
    {//T(N) = 3*T(N-2) + 2*F(N-3)
     //F(N) = T(N-1) + F(N-2)
        t[i] = 3*(i>=2 ? t[i-2] : 0) + 2*(i>=3 ? f[i-3] : 0);
        f[i] = (i>=1 ? t[i-1] : 0) + (i>=2 ? f[i-2] : 0);
    }
}

int main()
{
    int n;
    m();

    while(1)
    {
        cin>>n;

        if(n==-1)
            break;

        if(n==0)
            cout<<"1"<<endl;
        else if(n%2==1)
            cout<<"0"<<endl;
        else cout<<t[n]<<endl;
    }
    return 0;
}
