#include<bits/stdc++.h>

using namespace std;

string change(string s)
{
    string t;
    t.push_back('^');

    if(s.empty())
        return t;

    for(int i=0;i<s.size();i++)
    {
        t.push_back('$');
        t.push_back(s[i]);
    }
    t.push_back('$');

    t.push_back('*');

    return t;
}

int lps(string s, int &centre, int &freq)
{
    string t = change(s);
    int len = t.length();

    int *p = new int[len];
    int c=0;
    int l=0;
    int r=0;

    for(int i=1;i<len-1;i++)
    {
        int i_ = 2*c-i;

        if(r<=i)
            p[i] =0;
        else
        {
        if(p[i_] > r-i)
            p[i] = r-i;
        else if(p[i_] < r-i)
            p[i] = p[i_];
        else if(p[i_] == r-i)
            p[i] = r-i;
        }
            //p[i] = (r>i) ? min(r-i, p[i_]): 0;
            bool ext = 0;
            while(t[i-1-p[i]] == t[i+1+p[i]])
                {
                    p[i]++;
                    ext=1;
                }

            if(ext)
            {
                c = i;
                r = i+p[i];
            }
    }

    int ans=0;
    for(int i=1;i<len-1;i++)
    {//cout<<p[i]<< " ";
        if(p[i] > ans)
        {
            ans = p[i];
            centre = i;
            freq=1;
        }
        else if(p[i] == ans)
            freq++;
    }

    delete[] p;
    return ans;
}

int main()
{
int n;
cin>>n;
        string s;
        cin>>s;

        int centre = 0, freq=0;
        int l = lps(s, centre, freq);

        cout<<l<<endl;
    return 0;
}
