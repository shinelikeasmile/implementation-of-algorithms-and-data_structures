#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string s,string s1)
{
    return s.length()<=s1.length();
}
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    string prev;
	    cin>>prev;
	    while(--N)
	    {
	        string curr;
	        cin>>curr;
	        int length,i;
	        if(prev.length()>curr.length()) length=curr.length();
	        else length=prev.length();
	        for(i=0;i<length;i++)
	        {
	            if(prev[i]==curr[i]);
	            else break;
	        }
	        prev=prev.substr(0,i);
	    }
	    if(prev.length()==0)cout<<-1<<endl;
	    else cout<<prev<<endl;
	}
	return 0;
}
