#include<bits/stdc++.h>

using namespace std;

char d[1000001]={0};
char ff[1000001]={0};
int ith=1;

char f(int n, int k, int l)
{
    if(n <= 0)
    return 'B';

    if(n == 1)
    return 'A';

    if(ff[n] != ith)
    {
        int a = n-1, b = n-k, c = n-l;

        if(a>0 && f(a, k, l) == 'B')
        {
            d[n] = 'A';
        }
        else if(b>0 && f(b, k, l) == 'B')
        {
            d[n] = 'A';
        }
        else if(c>0 && f(c, k, l) == 'B')
        {
            d[n] = 'A';
        }
        else d[n] = 'B';

        ff[n] = ith;
    }

    return d[n];
}

char b(int n, int k, int l)
{
d[0]='B';
d[1]='A';

for(int i = 2; i <= n; i++)
{
    int a = i-1, b = i-k, c = i-l;

        if(a>=0 && d[a] == 'B')
        {
            d[i] = 'A';
        }
        else if(b>=0 && d[b] == 'B')
        {
            d[i] = 'A';
        }
        else if(c>=0 && d[c] == 'B')
        {
            d[i] = 'A';
        }
        else d[i] = 'B';
}

return d[n];
}

int main()
{
    int k, l, m;
    cin>>k>>l>>m;

    int n;
    for(int i=0;i<m;i++)
    {
        cin>>n;

        cout<<b(n, k, l);

        ith++;
    }
    cout<<endl;

    return 0;
}
