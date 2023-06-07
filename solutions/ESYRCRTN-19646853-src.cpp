#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,a;
        cin>>n;
        n=n%6;
        if(n==0)
            a=0;
        else if(n==1)
            a=1;
        else if(n==2)
            a=4;
        else if(n==3)
            a=6;
        else if(n==4)
            a=5;
        else if(n==5)
            a=2;
        cout<<a<<endl;
           }
    return 0;
}
