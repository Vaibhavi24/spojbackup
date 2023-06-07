#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<cstdio>
#include<map>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d\n",&n);
        string b;
        set<string>s;
        map<string, int> freq;

        char dummy[100];
        for(int i=0;i<n;i++)
        {
            //cin>>a>>c>>a1>>a2>>a3>>a4;
            //b=a+c+a1+a2+a3+a4;
            //cin>>space;
        gets(dummy);
        b=(string) dummy;
            freq[b]++;
            if(freq[b]==1)
                s.insert(b);
        }
        for(set<string>::iterator it=s.begin();it!=s.end();it++)
            printf("%s %d\n",(*it).c_str(),freq[*it]);
            if(t>1)
                printf("\n");
    }
    return 0;
}


