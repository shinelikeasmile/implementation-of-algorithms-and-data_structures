#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


void combinations_helper(vector<int>&input,vector<char>&output,int index)
{
	if(!output.empty())
	{
		copy(output.begin(),output.end(),ostream_iterator<char>(cout," "));
		cout<<endl;
	}
	for(int i=index;i<26;i++)
	{
		if(input[i])
		{
			input[i]--;
			output.emplace_back(char(i+65));
			combinations_helper(input,output,i);
			input[i]++;
			output.pop_back();
		}
	}
}
void combinations(string str)
{
	vector<int>input(26);
	for(char s:str)
	{
		input[s-'A']++;
	}
	vector<char>output;
	combinations_helper(input,output,0);
	
}
int main()
{
	string str;
	cin>>str;
	combinations(str);
}
