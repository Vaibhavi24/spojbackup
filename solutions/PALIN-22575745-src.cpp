#include<bits/stdc++.h>

using namespace std;

void clean(string &s)
{
	int flag=0;

	int i=0, j=0, n=s.length();

	while(j<n && s[j]=='0')
		j++;

	while(j<n)
		s[i++] = s[j++];
//cout<<"HH";
	if(i!=n)
	s.erase(s.begin()+i, s.end());
}

bool all9(string s)
{//cout<<"GG";
	for(int i=0;s[i]!='\0';i++)
		if(s[i]!='9')
			return false;

	return true;
}

bool isPal(string s)
{
	int i=0, j=s.length()-1;

	while(i<j)
		{
		    if(s[i]!=s[j])
			return false;

		    i++; j--;
		}
	return true;
}

void add1(string &s)
{
	int carry = 1, n = s.length();
	reverse(s.begin(), s.end());

	for(int i=0;i<n;i++)
	{
		int val = s[i]-'0' + carry;

		carry = val/10;
		s[i] = (char) val%10 + '0';

		if(carry == 0)
			break;
	}

	while(carry)
	{
		s += (char) carry + '0';
		carry /= 10;
	}

	reverse(s.begin(), s.end());
}

string mirror(string s)
{
	string r = s;
	reverse(r.begin(), r.end());

	return r;
}

string nextPalindrome(string s)
{
	int n = s.length();
	
	string FH="", mid="", SH="";
	string ans = "";

	if(all9(s))
	{
		ans = "1";

		for(int i=1;i<n;i++)
			ans+="0";

		ans+="1";

		return ans;
	}
//cout<<"YY";
	int i=0;
	bool odd = n%2, even = 1-n%2;

	for(;i<n/2;i++)
		FH += s[i];

	if(odd)
	{
		mid = s[n/2];
		i++;
	}

	if(isPal(s))
	{
		if(mid.empty() || mid == "9")
		{//cout<<"ADDING";
			add1(FH);
			if(odd)
				mid = "0";
		}
		else
		{
			int x = mid[0]-'0' + 1;

			mid = (char) x + '0';
		}

		SH = mirror(FH);
	//	cout<<ans;
		ans = FH+mid+SH;

		return ans;
	}
	else
	{
		SH = mirror(FH);

		ans = FH+mid+SH;

		if(ans < s)
			return nextPalindrome(ans);

		return ans;
	}
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;

		clean(s);

		cout<<nextPalindrome(s)<<endl;
	}
	return 0;
}