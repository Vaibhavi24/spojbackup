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
        }
        for(map<string,int>::iterator it=freq.begin();it!=freq.end();it++)
            printf("%s %d\n",(*it).first.c_str(),(*it).second);
            if(t>1)
                printf("\n");
    }
    return 0;
}


