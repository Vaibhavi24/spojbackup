#include<bits/stdc++.h>

struct activity
{
    int start,finish,profit;
};

using namespace std;

class comp
{
  public:
      bool operator()(activity a1,activity a2)
      {
          return (a1.finish<a2.finish);
      }
};

int latest_activity(activity job[],int k)
{
    int l=0,r=k-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
    if(job[mid].finish<=job[k].start)
    {
        if(job[mid+1].finish<=job[k].start)
            l=mid+1;
        else return mid;
    }
    if(job[mid].finish>job[k].start)
        r=mid-1;
    }
    return -1;
}

int dp[10004];
activity job[10004];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        job[i].start=x;job[i].finish=y+x;job[i].profit=z;
    }

    sort(job,job+n,comp());

    dp[0]=job[0].profit;

    for(int i=1;i<n;i++)
    {
        int addto=latest_activity(job,i);
        dp[i]=max(dp[i-1], job[i].profit + ((addto>-1)?dp[addto]:0));

    }
    printf("%d\n",dp[n-1]);
    }
    return 0;
}
