//equilibrium index is the index where the sum of the elements before it inclusively equal to the sum of the elements after it.
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int size;
  cin>>size;
  vector<int>v;
  while(size--)
  {
    int temp;cin>>temp;
    v.push_back(temp);
  }
  int total=0;
  for(auto x:v)
  {
    total=total+x;
  }
  int leftsum=0;
  for(unsigned int i=0;i<v.size();i++)
  {
    if(leftsum==(total-v[i])/2){cout<<i;break;}
    leftsum=leftsum+v[i];
  }
}
