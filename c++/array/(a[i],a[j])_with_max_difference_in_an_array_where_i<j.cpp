#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> v;
	int size;
	cin>>size;
	int temp;
	while(size--)
	{
		cin>>temp;
		v.push_back(temp);
	}
	int minsf=v[0],maxdsf=v[1]-v[0],curd=v[1]-v[0];
	for(auto x:v)
	{
		if(x<minsf)minsf=x;
		curd=x-minsf;
		if(curd>maxdsf)maxdsf=curd;
	}
	cout<<maxdsf;
}
