#include<stdio.h>
#include<iostream>

using namespace std;

typedef long long int ll;

int a[200001]={0};

ll countSplit(int l, int r)
{
	int *c = new int[r-l+1];

	int mid = (l+r)/2;
	int n = mid+1, m = r+1;
	int i = l, j = mid+1, k = 0;

	ll ct = 0;
	while(i<n && j<m)
	{
		if(a[i] <= a[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = a[j++];
			ct     += (ll)(n-i);
		}
	}

	while(i<n)
		c[k++] = a[i++];

	while(j<m)
		c[k++] = a[j++];

	for(int i=0;i<k;i++)
		a[i+l] = c[i];

	return ct;
}

ll countInv(int l, int r)
{
	if(l == r)
	return 0;

	ll invLeft = countInv(l, (l+r)/2);
	ll invRight = countInv((l+r)/2 + 1, r);
	ll invSplit = countSplit(l, r);

	return invLeft+invRight+invSplit;
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
	int n;
	scanf("%d", &n);

	int i=0;
	while(i<n)
	{
		scanf("%d", &a[i++]);
	}

	printf("%llu\n", countInv(0, n-1));
	}
	return 0;
}