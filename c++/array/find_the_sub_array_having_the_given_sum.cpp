	#include <bits/stdc++.h>
	using namespace std;
	int main()
	{
		map<signed int,unsigned int>m;
		vector<int>v;
		int n;
		cout<<"no.of elements ";
		cin>>n;
		int r;
		cout<<"sum ";
	    cin>>r;//given sum
	    cout<<"enter elements ";
		while(n--)
		{
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		cout<<endl;
		signed int sum=0;
		for(unsigned int i=0;i<v.size();i++)
		{
			sum+=v[i];
			cout<<sum<<endl;
			if(sum==r){for(auto itr=v.begin();itr<=v.begin()+i;itr++)cout<<*itr<<" ";break;}
			else if(m.find(sum-r)!=m.end())
			{
				for(auto itr=v.begin()+m.find(sum-r)->second+1;itr<=v.begin()+i;itr++)cout<<*itr<<" ";
				break;			
			}
			else{m[sum]=i;}
		}
		
	}
