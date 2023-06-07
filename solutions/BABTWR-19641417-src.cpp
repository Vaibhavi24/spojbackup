#include<bits/stdc++.h>

using namespace std;

struct box
{
    int height,depth,width;
};

class Compare
{
public:
    bool operator()(box b1,box b2)
    {return (b1.width*b1.depth>b2.width*b2.depth);}
};

int main()
{
    int n;
    while(scanf("%d",&n)>0)
    {
        if(n==0)
            break;
    box b[n]; box rotated[3*n];
    int k=0;
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&b[i].height,&b[i].width,&b[i].depth);

    for(int i=0;i<n;i++)
    {
        rotated[k].height=b[i].height;
        rotated[k].width=max(b[i].depth, b[i].width);
        rotated[k].depth=min(b[i].depth, b[i].width);

        k++;

        rotated[k].height=b[i].depth;
        rotated[k].width=max(b[i].height, b[i].width);
        rotated[k].depth=min(b[i].height, b[i].width);
        k++;

        rotated[k].height=b[i].width;
        rotated[k].width=max(b[i].height, b[i].depth);
        rotated[k].depth=min(b[i].height, b[i].depth);
        k++;
    }
    n=3*n;
    sort(rotated,rotated+n,Compare());
    int inc_h[n],maxg=0;

    for(int i=0;i<n;i++)
        inc_h[i]=rotated[i].height;

    for(int i=0;i<n;i++)
        {   for(int j=0;j<i;j++)
    {
        if(rotated[j].width>rotated[i].width && rotated[j].depth>rotated[i].depth && inc_h[j] + rotated[i].height > inc_h[i])
            inc_h[i]=inc_h[j] + rotated[i].height;
    }
            if(inc_h[i]>maxg) maxg=inc_h[i];
     }
        printf("%d\n",maxg);
    }
    return 0;
}
