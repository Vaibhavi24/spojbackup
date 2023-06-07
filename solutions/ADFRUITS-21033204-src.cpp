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
        //if(dir[i][j] == 'u')
        {
            s = mrg(a, b, i-1, j);
            s += a[i-1];
        }
    }

    if(j>0 && i==0)
    {
        //if(dir[i][j] == 's')
        {
            s = mrg(a, b, i, j-1);
            s += b[j-1];
        }
    }

    if(j==0 && i==0)
        return s;

    return s;
}

string merge(string a, string b, string c, int n, int m)
{
    string mg;

    int i=0, j=0, k=0;
    while(i<n && j<m)
    {
        if(k<c.length()&&a[i]==c[k])
        {
            i++;
            k++;
        }
        else
        {
            mg += a[i];
            i++;
        }

        if(k<c.length()&&b[j]==c[k])
        {
            j++;
            k++;
        }
        else
        {
            mg += b[j];
            j++;
        }
    }

    while(i<n)
    {
        if(k<c.length()&&a[i]==c[k])
        {
            i++;
            k++;
        }
        else
        {
            mg += a[i];
            i++;
        }
    }

    while(j<m)
    {
        if(k<c.length()&&b[j]==c[k])
        {
            j++;
            k++;
        }
        else
        {
            mg += b[j];
            j++;
        }
    }

    return mg;
/*
    int freq[256]={0};
    for(int i=0;i<c.length();i++)
    freq[c[i]]++;

    c.clear();
    c = a;
    for(int j=0;j<m;j++)
        if(freq[b[j]]==0)
        c += b[j];
        else freq[b[j]]--;

    int j=0, k=0;
    for(int i=0;i<c.length();i++)
        {
        if(j<n && a[j] == c[i])
        j++;

        if(k<m && b[k] == c[i])
        k++;
        }

    if(j==n && k==m)
        return c;

    c.clear();
    c = b;

    for(int i=0;i<c.length();i++)
    freq[c[i]]++;

     for(int i=0;i<n;i++)
        if(freq[a[i]]==0)
        c += a[i];
        else freq[a[i]]--;

    return c;
*/
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
