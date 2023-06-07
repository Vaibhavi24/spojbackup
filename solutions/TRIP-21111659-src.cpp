#include<bits/stdc++.h>

using namespace std;

int d[101][101]={0};

void f(string a, string b, int n, int m)
{
set<string> s[2][101];

for(int i=1;i<=n;i++)
    d[i][0] = 0;

for(int j=0;j<=m;j++)
{
    d[0][j] = 0;
    s[0][j].insert("");
    s[1][j].insert("");
}

for(int i = 1;i<=n;i++)
{
    for(int j = 1;j<=m;j++)
    {
        if(a[i-1]==b[j-1])
            {
                d[i][j] = 1+d[i-1][j-1];
                s[i%2][j].clear();

                for(set<string>::iterator it = s[1-i%2][j-1].begin(); it!=s[1-i%2][j-1].end();it++)
                {
                    string str = *it;
                    str += a[i-1];
                    s[i%2][j].insert(str);
                }
            }
        else
            {
                if(d[i-1][j] == d[i][j-1])
                {
                    d[i][j] = d[i-1][j];
                    s[i%2][j] = s[1-i%2][j];

                    for(set<string>::iterator it=s[i%2][j-1].begin(); it!=s[i%2][j-1].end(); it++)
                        s[i%2][j].insert(*it);
                }
                else if(d[i-1][j] > d[i][j-1])
                {
                    d[i][j] = d[i-1][j];
                    s[i%2][j] = s[1-i%2][j];
                }
                else
                {
                    d[i][j] = d[i][j-1];
                    s[i%2][j] = s[i%2][j-1];
                }
            }
    }
}

for(set<string>::iterator it = s[n%2][m].begin(); it!=s[n%2][m].end();it++)
    cout<<(*it)<<endl;

}

set<string> printall(string a, string b, int i, int j)
{
set<string> ans;

if(i==0 || j==0)
{
    string s;
    ans.insert(s);
    return ans;
}

if(a[i-1] == b[j-1])
{
    set<string> temp = printall(a, b, i-1, j-1);

    for(set<string>::iterator it=temp.begin(); it!=temp.end(); it++)
    {
        string x = *it;
        x += a[i-1];
        ans.insert(x);
    }
}
else
{
    if(d[i-1][j]>0 && d[i-1][j] == d[i][j-1])
    {
        set<string> up = printall(a, b, i-1, j);
        ans.insert(up.begin(), up.end());

        if(ans.size()<1000)
        {
        set<string> side=printall(a, b, i, j-1);
        ans.insert(side.begin(), side.end());
        }
    }
    else if(d[i-1][j] > d[i][j-1])
    {
        set<string> up = printall(a, b, i-1, j);
        ans.insert(up.begin(), up.end());
    }
    else if(d[i][j-1] > d[i-1][j])
    {
        set<string> side=printall(a, b, i, j-1);
        ans.insert(side.begin(), side.end());
    }
}

return ans;
}

/**
1
abcabcaa
acbacba
**/

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string a, b;
        cin>>a>>b;

        int n = a.length(), m = b.length();
        f(a, b, n, m);
        /*
        set<string> all = printall(a, b, n, m);

        for(set<string>::iterator it=all.begin(); it!=all.end(); it++)
            cout<<(*it)<<endl;
        */
    }
    return 0;
}
