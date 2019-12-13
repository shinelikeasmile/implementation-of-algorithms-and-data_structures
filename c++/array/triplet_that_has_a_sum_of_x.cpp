#include <bits/stdc++.h>
using namespace std;
int main()
{
  int size;
  cin>>size;
  vector<int>v;
  int x;
  cin>>x;
  while(size--)
  {
    int temp;
    cin>>temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  for(unsigned int i=0;i<v.size()-2;i++)
  {
    for(int j=i+1,k=v.size()-1;j<k;)
    {
        if(v[i]+v[j]+v[k]==x){
          cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
		  break;}
        else if(v[i]+v[j]+v[k]>x)k--;
        else j++;
    }
  }
}
