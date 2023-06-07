#include<stdio.h>
#include<iostream>
using namespace std;
long long int arr[50001]={0};
struct nodde
{
    long long int total_sum,bestmax_sum,hinge_left,hinge_right;
} ;
nodde tree[200001]={0};
nodde combine(nodde left,nodde right)
{
    nodde v;
    v.total_sum=left.total_sum+right.total_sum;
    v.hinge_left=max(left.hinge_left, left.total_sum+right.hinge_left);
    v.hinge_right=max(right.hinge_right,right.total_sum+left.hinge_right);
    v.bestmax_sum=max(left.hinge_right+right.hinge_left,max(left.bestmax_sum,right.bestmax_sum));
    return v;
}

/**
 * Build and init tree
 */

void build_tree(long long int node, long long int a, long long int b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
            nodde v;
    v.total_sum=arr[a];
    v.bestmax_sum=arr[a];
    v.hinge_left=arr[a];
    v.hinge_right=arr[a];
    		tree[node]=v;
    		        return ;
  	}
    build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    tree[node]=combine(tree[node*2],tree[node*2+1]);
    }

/**
 * Query tree to get max element value within range [i, j]
 */
nodde query_tree(long long int node, long long int a, long long int b, long long int i, long long int j) {

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

    if(j<=(a+b)/2)
	return query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	if(i>(a+b)/2)
	return query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

		nodde q1,q2;
q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
    nodde res=combine(q1,q2);

	return res;
}

/*
5
-7 8 9 -10 2
*/
int main()
{
    long long int n;
    scanf("%lld",&n);
    scanf("%lld",&arr[0]);

    for(long long int i=1;i<n;i++)
            scanf("%lld",&arr[i]);

build_tree(1,0,n-1);
long long int m;
    scanf("%lld",&m);
while(m--)
{
    long long int l,r;
        scanf("%lld%lld",&l,&r);
    nodde ans=query_tree(1,0,n-1,l-1,r-1);
        printf("%lld\n",ans.bestmax_sum);
}
    return 0;
}
