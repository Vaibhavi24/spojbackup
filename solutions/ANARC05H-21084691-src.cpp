#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int ff[25][226]={0};
ll d[25][226]  ={0};
int ith = 1;

ll f(int i, int K, int a[], int n)
{
if(i<0)
return 1;
/*
if(i == 0)
{
if(a[i] <= K)
return 1;
else return 0;
}
*/
if(ff[i][K] != ith)
{
    ff[i][K] = ith;
    d[i][K]  = 0;

    int sum = 0;
    for(int sz = 1; sz<=i+1; sz++)
    {
        if(sum + a[i-sz+1] <= K)
        d[i][K] += f(i-sz, sum + a[i-sz+1], a, n);
        else break;

        sum = sum + a[i-sz+1];
    }
}

return d[i][K];
}

int main()
{
    string s;
    while(1)
    {
        cin>>s;

        if(s == "bye")
            break;

        int n = s.length();
        int a[n];
        for(int i=0;i<n;i++)
        a[i] = (int) s[i]-'0';

        cout<<ith<<". "<<f(n-1, 226, a, n)<<endl;

        ith++;
    }
    return 0;
}
