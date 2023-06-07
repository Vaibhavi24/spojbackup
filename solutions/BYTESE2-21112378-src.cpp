#include<bits/stdc++.h>

using namespace std;

struct Time
{
    int t;
    int type;
};

class comp
{
public:
    bool operator()(Time t1, Time t2)
    {
        return (t1.t <= t2.t);
    }
};

int main()
{
    int c;
    cin>>c;

    while(c--)
    {
        int n;
        cin>>n;

        int t, type;
        vector<Time> v;
        for(int i=0;i<2*n;i++)
        {
            cin>>t;

            Time temp;
            temp.t=t;
            temp.type=i%2;

            v.push_back(temp);
        }

        sort(v.begin(), v.end(), comp());

        int curr=0;
        int ans=0;

        for(int i=0;i<2*n;i++)
        {
            Time ith = v[i];

            if(ith.type == 0)
                curr++;
            else curr--;

            ans = max(ans, curr);
        }

        cout<<ans<<endl;
    }
    return 0;
}
