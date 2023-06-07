#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
typedef unsigned long long ull;
using namespace std;
char expression[100]={0};
vector<int> num;
vector<char> opr;
string buff;

ull maxd[100][100];
ull mind[100][100];

bool isOperator(char x)
{ return ((x=='+')||(x=='*'));
}

void separate(int len)
{
    num.clear(); opr.clear(); buff=" ";
for(int i=0;i<=len;i++)
{
    if(isOperator(expression[i]))
    {
        opr.push_back(expression[i]);
        num.push_back((ull)atoi(buff.c_str()));
        buff=" ";
    }
    else buff+=expression[i];
}
 num.push_back(atoi(buff.c_str()));
}


void compute_min_max(int n)
{
    int sz=num.size();
    for(int i=0;i<sz;i++)
      {for(int j=0;j<sz;j++)
      {
          if(i==j)
            { mind[i][j]=num[i]; maxd[i][j]=num[i];
            }
            else { mind[i][j]=ULONG_LONG_MAX; maxd[i][j]=0;}
      }}

    for(int L=2;L<=sz;L++)
        for(int i=0;i<sz-L+1;i++)
        {int j=i+L-1;
            for(int k=i;k<j;k++)
            { int kmin=0,kmax=0;

                if(opr[k]=='+')
                {
                    kmin=mind[i][k]+mind[k+1][j];
                kmax=maxd[i][k]+maxd[k+1][j];
                }
               else if(opr[k]=='*')
                {
                   kmin=mind[i][k]*mind[k+1][j];
                   kmax=maxd[i][k]*maxd[k+1][j];
                }
            if(kmin<mind[i][j])
            mind[i][j]=kmin;
            if(kmax>maxd[i][j])
            maxd[i][j]=kmax;
        }
            }

        cout<<maxd[0][sz-1]<<" "<<mind[0][sz-1]<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>expression;
       int len=0;
       for(int i=0;expression[i]!='\0';i++)
        len++;
       separate(len);
       compute_min_max(len);
    }
    return 0;
}
