//two_pointer_technique.
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int size;
	cin>>size;
	vector<int> v;
	while(size--)
	{
		int temp;cin>>temp;
		v.push_back(temp);
	}
	for(unsigned int i=0,j=v.size()-1;i<j;)
	{
		while(v[i]==0)i++;
		while(v[j]==1)j--;
		if(i<j){
		v[i]=0;v[j]=1;
		i++;j--;}
	}
	for(auto x:v)cout<<x;
}
