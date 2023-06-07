#include<stdio.h>
#include<iostream>
using namespace std;
struct nodde
{
    long long int total_sum,lazy;
} ;
nodde tree[4000001]={0};
/**
 * Build and init tree
 */

void build_tree(long long int node, long long int a, long long int b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
            nodde v;
    v.total_sum=0LL;
    v.lazy=0LL;
    		tree[node]=v;
    		        return ;
  	}
    build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    tree[node].total_sum=0LL;
    tree[node].lazy=0LL;
    }

/**
 * Query tree to get max element value within range [i, j]
 */
nodde query_tree(long long int node, long long int a, long long int b, long long int i, long long int j) {

    if(tree[node].lazy!=0LL)
    {
           if(a!=b)
        {
            tree[2*node].lazy+=tree[node].lazy;
            tree[2*node+1].lazy+=tree[node].lazy;
        }
        tree[node].total_sum+=1LL*(b-a+1)*tree[node].lazy;
        tree[node].lazy=0LL;
    }


	if(i>b||j<a||a>b)
    {
        nodde res;res.total_sum=0LL;res.lazy=0LL;
        return res;
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
		{
		    return tree[node];
		}

    nodde q1,q2,res;
q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    res.total_sum=q1.total_sum+q2.total_sum;

	return res;
}


void update_tree(long long int node, long long int a, long long int b, long long int i, long long int j, long long int val)
{
    if(tree[node].lazy!=0LL)
    {
        if(a!=b)
        {
            tree[2*node].lazy+=tree[node].lazy;
            tree[2*node+1].lazy+=tree[node].lazy;
        }
        tree[node].total_sum+=1LL*(b-a+1)*tree[node].lazy;
        tree[node].lazy=0LL;
    }

    if(a>=i && b<=j)
    {
        tree[node].total_sum+=1LL*(b-a+1)*val;
        if(a!=b)
           {
            tree[2*node].lazy+=val;
           tree[2*node+1].lazy+=val;
           }
           tree[node].lazy=0LL;
            return ;
    }

    if(i>b||j<a||a>b)
        return;

        update_tree(2*node+1,(a+b)/2 +1, b,i,j,val);
        update_tree(2*node, a,(a+b)/2,i,j,val);

    tree[node].total_sum=tree[2*node].total_sum+ tree[(2*node)+1].total_sum;

    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,c;
        scanf("%d%d",&n,&c);
for(int i=0;i<n;i++)
{tree[i].lazy=0;tree[i].total_sum=0;}
        build_tree(1,0,n-1);

        while(c--)
        {
            int type,x,y;
            scanf("%d%d%d",&type,&x,&y);
            if(type==1)
            {   nodde ans=query_tree(1,0,n-1,x-1,y-1);
                printf("%lld\n",ans.total_sum);
            }
            else
                {
                    long long int val;
                    scanf("%lld",&val);
                update_tree(1,0,n-1,x-1,y-1,val);
                }
        }
    }
    return 0;
}
