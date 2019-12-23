	#include <bits/stdc++.h>
	using namespace std;

	int main()
	{
		vector<int> v;
		int n;
		cout<<"enter size of the array :";
		cin>>n;
		cout<<"enter elements :";
		while(n--)
		{
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		cout<<endl;
		sort(v.begin(),v.end());
		deque <vector<int>::iterator> d1,d2,d0;
		int sum=0;
		for(auto itr=v.begin();itr!=v.end();itr++)
		{
			sum+=*itr;
			if(*itr%3==0){d0.push_back(itr);}
			else if(*itr%3==1){d1.push_back(itr);}
			else {d2.push_back(itr);}
		}
		if(sum%3==1)
		{
			if(!d1.empty()){v.erase(d1.back());d1.pop_back();}
			else
			{
				if(!d2.empty() && d2.size()>=2 ){ v.erase(d2.back());d2.pop_back();v.erase(d2.back());d2.pop_back();}
				else{ cout<<"cannot make a multiple of 3 "; return 0;}
			}
			
		}
		else if(sum%3==2)
		{
			if(!d2.empty()){v.erase(d2.back());d2.pop_back();}
			else
			{
				if(!d1.empty() && d1.size()>=2 ){ v.erase(d1.back());d1.pop_back();v.erase(d1.back());d1.pop_back();}
				else{cout<<"cannot make a multiple of 3";return 0;}
			}	
		}
		else{}
		if(v.size()==0)cout<<"cannot make a multiple of 3";
		for(auto itr=v.end()-1;itr>=v.begin();itr--)
			{
			cout<<*itr;
			}	
	}
