#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void permutation_helper(int alpha[],vector<char>&output,unsigned int length)
{
	if(output.size()==length)
	{
		copy(output.begin(),output.end(),ostream_iterator<char>(cout,","));
		cout<<endl;
	}
	for(int i=0;i<26;i++)
	{
		if(alpha[i]!=0)
		{
			output.emplace_back(char(i+'A'));
			alpha[i]--;
			permutation_helper(alpha,output,length);
			alpha[i]++;
			output.erase(output.end()-1);
			
		}
	}
}
void permutation(string str)
{
	int alpha[26]={0};
	for(char c:str)
	{ 
		alpha[c-'A']++;
	}
	vector<char>output;
	permutation_helper(alpha,output,str.length());
}
int main()
{
	string str;
	cin>>str;
	permutation(str);
}
