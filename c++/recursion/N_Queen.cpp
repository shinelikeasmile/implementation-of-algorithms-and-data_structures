#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


bool N_Queen_helper(vector<vector<int>>&squares,vector<pair<unsigned int,unsigned int>>&positions,int n)
{
	if(n>0)
	{
		for(unsigned int i=0;i<squares.size();i++)
		{
			bool attack=false;
			for(auto pos:positions)
			{
				if( n-1==pos.first || i==pos.second || n-1-i==pos.first-pos.second || n-1+i==pos.first+pos.second)
					{
						attack=true;
						break;
					}
			}
			if(attack==false)
			{
				positions.emplace_back(make_pair(n-1,i));
				if(N_Queen_helper(squares,positions,n-1))
				{
					squares[n-1][i]=1;
					return true;
				}
				positions.erase(positions.end()-1);
			}
		}
		return false;
	}
	return true;
}
void N_Queen(int n)
{
	vector<vector<int>>squares(n,vector<int>(n));
	vector<pair<unsigned int,unsigned int>>positions;
	N_Queen_helper(squares,positions,n);
	for(vector<int>row:squares)
	{
		copy(row.begin(),row.end(),ostream_iterator<int>(cout,"  "));
		cout<<endl<<endl;
	}
}
int main()
{
	int n;
	cout<<"N : ";
	cin>>n;
	N_Queen(n);
}
