#include<bits/stdc++.h>
using namespace std;

int lps[1000000]={0};int ct=0,x=0;
char s[1000000],p[1000000];

void computeLPS(char p[],int M)
{
    int len=0,i=1;
    lps[0]=0;
    while(i<M)
    {
        if(p[len]==p[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else if(len!=0)
        {
            len=lps[len-1];
        }
        else
        {
            lps[i]=0;
            i=i+1;
        }
    }
}

void KMPsearch(char needle[],char haystack[],vector<int> &pos,int ln,int lh)
{
    int i=0,j=0,k=0;ct=0;

    computeLPS(needle,ln);

    while(i<lh)
    {
        if(haystack[i]==needle[j])
        {
            i++; j++;
        }

        if(j==ln)
        {
            pos.push_back(i-j);
            ct++;
            j=lps[j-1];
        }

        else if(i<lh && haystack[i]!=needle[j])
        {
            if(j>0)
            j=lps[j-1];
            else
            i=i+1;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%s %s",s,p);
    int i=0,ls=0,lp=0;
    for(;s[i]!='\0'&&p[i]!='\0';i++) ;

    if(s[i]=='\0') {
        ls=i;

    for(;p[i]!='\0';i++);
    lp=i;
    }

    else {
        lp=i;

    for(;s[i]!='\0';i++);
    ls=i;
    }
    vector<int> pos;
    KMPsearch(p,s,pos,lp,ls);

    if(pos.size()>0)
    {
        printf("%d\n",pos.size());
        for(int i=0;i<pos.size();i++)
            printf("%d ",pos[i]+1);
    printf("\n");
    }
    else printf("Not Found\n");

   printf("\n");
    }
    return 0;
}

