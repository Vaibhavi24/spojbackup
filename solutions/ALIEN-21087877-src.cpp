#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int a[100001]={0};
int d[100001]={0};

int f(int n, int K, int &s)
{
int l = 0;
int ans = 0;
int sum = 0;

for(int i=0;i<n;i++)
{
    sum += a[i];

    while(sum>K && l<=i)
    {
        sum -= a[l];
        l++;
    }

    if(i-l+1 > ans)
    {
        ans = i-l+1;
        s = sum;
    }

    if(i-l+1 == ans)
    {
        s = min(s, sum);
    }
}

return ans;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n, b;
        scanf("%d%d", &n, &b);

        for(int i=0;i<n;i++)
            {
                scanf("%d", &a[i]);
                d[i] = 0;
            }

        int s = 0, ans = f(n, b, s);
        printf("%d %d",s,ans);
        printf("\n");
    }

    return 0;
}
