#include<bits/stdc++.h>

using namespace std;
/**
sssssssssssssssssssssssssssssssssssssssffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhh
**/

int d[101][101]={0};
char dir[101][101]={0};

int f(string a, string b, int n, int m)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        d[i][j]=0;

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                d[i][j]   = 0;
                dir[i][j] = 'u';
                continue;
            }

            if(a[i-1]==b[j-1])
            {
                d[i][j] = 1+d[i-1][j-1];
                dir[i][j] = 'a';
            }
            else
            {
                if(d[i-1][j] >= d[i][j-1])
                {
                    d[i][j]   = d[i-1][j];
                    dir[i][j] = 'u';
                }
                else
                {
                    d[i][j]   = d[i][j-1];
                    dir[i][j] = 's';
                }
            }
        }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        cout<<dir[i][j]<<" ";
        cout<<endl;
    }*/
    return d[n][m];
}
//conservatives breather
string print(string a, string b, int i, int j)
{
    string s;

    if(i>0 && j>0)
    {
        if(dir[i][j]=='a')
        {
            s = print(a, b, i-1, j-1);
            s += a[i-1];
        }
        else if(dir[i][j] == 'u')
            s = print(a, b, i-1, j);
        else s= print(a, b, i, j-1);
    }

    return s;
}

string mrg(string a, string b, int i, int j)
{
    string s;

    if(i>0 && j>0)
    {
        if(dir[i][j]=='a')
        {
            s = mrg(a, b, i-1, j-1);
            s += a[i-1];
        }
        else if(dir[i][j] == 'u')
            {
                s = mrg(a, b, i-1, j);
                s += a[i-1];
            }
        else
        {
            s= mrg(a, b, i, j-1);
            s+= b[j-1];
        }
    }

    if(i>0 && j==0)
    {
            s = mrg(a, b, i-1, j);
            s += a[i-1];
    }

    if(j>0 && i==0)
    {
            s = mrg(a, b, i, j-1);
            s += b[j-1];
    }

    if(j==0 && i==0)
        return s;

    return s;
}

int main()
{
    string a, b;

    while(!cin.eof())
    {
    cin>>a;
    cin>>b;

    int n = a.length(), m = b.length();
    int l = f(a, b, n, m);
    string c = print(a, b, n, m);//cout<<c<<endl;
    cout<<mrg(a, b, n, m)<<endl;
    }
    return 0;
}
