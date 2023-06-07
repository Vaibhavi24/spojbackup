#include<stdio.h>
#include<iostream>


    int lcs[5001][5001]={0};
int main()
{
int la,i=0; char a[5001]={0};
scanf("%d",&la);
scanf("%s",a);

for(int x=0;x<=la;x++)
            for(int y=0;y<=la;y++)
            {
                if(x==0||y==0)
                    lcs[x%2][y]=0;
               else if(a[x-1]==a[la-y])
                    lcs[x%2][y]=1+lcs[(x-1)%2][y-1];
                  else  lcs[x%2][y]=std::max(lcs[(x-1)%2][y],lcs[x%2][y-1]);
            }

        printf("%d\n",(la-lcs[la%2][la]));
    return 0;
}

