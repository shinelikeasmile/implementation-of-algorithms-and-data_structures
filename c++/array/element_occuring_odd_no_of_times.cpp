//to find the element which occurs odd no.of times just Xor all the elements.
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int size;
  cin>>size;
  vector<int>v;
  while(size--)
  {
	  int temp;
	  cin>>temp;
	  v.push_back(temp);
  }
  int Xor=0;
  for(auto x:v)
  {
    Xor=Xor^x;
  }
  cout<<Xor;
}
