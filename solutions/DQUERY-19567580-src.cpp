#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct q
{
    int l,r,indx;
};

int n,ans=0;

int arr[200008]={0};
q query[200008];
int countt[1000001]={0};
int val[200008]={0};

class Compare
{
    public :
    bool operator() (q p1,q p2)
{
    int sz=sqrt(n);

    int blk1=p1.l/sz,blk2=p2.l/sz;
    if(blk1!=blk2) return (blk1<blk2);
    else return (p1.r<p2.r);
}};

void fminus(int x)
{
    if(countt[x]==1)
    ans-=1;
    countt[x]--;
}

void fplus(int x)
{
    countt[x]++;
    if(countt[x]==1)
    ans+=1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
   scanf("%d",&arr[i]);
            countt[arr[i]]=0;
        }
    int t;
   scanf("%d",&t);
        int i=0;
    while(i<t)
    {
        int l ,r;
   scanf("%d %d",&l,&r);
        --l;--r;
        query[i]=(q){l,r,i};
        i++;
    }
sort(query,query+t,Compare());

int mo_left=0,mo_right=-1;

for(int i=0;i<t;i++)
{
    int L=query[i].l,R=query[i].r,in=query[i].indx;

    while(mo_left<L)
        {
            fminus(arr[mo_left]);
            mo_left++;
        }
    while(mo_left>L)
        {mo_left--;
            fplus(arr[mo_left]);
        }

    while(mo_right<R)
        {mo_right++;
            fplus(arr[mo_right]);
        }
    while(mo_right>R)
        {
            fminus(arr[mo_right]);
            mo_right--;
        }
        val[in]=ans;
}

for(int i=0;i<t;i++)
{
    printf("%d\n",val[i]);
}
    return 0;
}
