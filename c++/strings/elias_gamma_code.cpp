#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string tobinary(int i)
{
	string result="";
	while(i)
	{
		result=char(i%2+'0')+result;
		i=i/2;
	}
	i=result.length();
	while(i--)
	{
		result='0'+result;
	}
	return result;
}
string Encode(vector<int>&Array)
{
	string result="";
	for(int i:Array)
	{
		result=result+tobinary(i);
	}
	return result;
}
void Decode(string encoded)
{
	int counting=1;
	int count=0;
	int output=0;
	for(char e :encoded)
	{
		if(e == '0' && counting == 1)
			count++;
		else if(e == '0' &&  count)
			count--;
		else if(e == '1')
			{
				counting = 0;
				output+=pow(2,--count);
			}
		if(!count)
		{
			counting=1;
			cout<<output<<" ";
			output=0;
		}		
	}
}
int main()
{
	vector<int>Array;
	int n;
	cout<<"enter n : ";
	cin>>n;
	cout<<"enter elements : ";
	while(n--)
	{
		int temp;
		cin>>temp;
		Array.push_back(temp);
	}
	string encoded =  Encode(Array);
	cout<<"\nElias gamma code"<<endl;
	cout<<"encoded : "<<encoded<<endl;
	cout<<"decoded : ";
	Decode(encoded);
	
}
