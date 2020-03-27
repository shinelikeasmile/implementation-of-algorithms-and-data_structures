#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>&v,int start,int end,int element)
{
    if(start<=end)
    {
        if(start==end)
        {
            if(v[start]>element) return start;
            else return -1;
        }
        int mid=start+(end-start+1)/2;
        if(v[mid]<=element)
        {
            int index = binary_search(v,mid+1,end,element);
            return index;
        }
        else if(v[mid]>element && v[mid-1]>element)
        {
            int index = binary_search(v,start,mid-1,element);
            return index;
        }
        else if(v[mid]>element && v[mid-1]<=element) return mid;
        
    }
    return -1;
}
int main() {
	cout<<"No of Test Cases : ";
    int T;
    cin>>T;
    while(T--)
    {
		cout<<"Enter sizes of two arrays : ";
        int M,N,temp;
        cin>>M>>N;
        vector <int> X;
        vector <int> Y;
        cout<<"Enter values of first array : "<<endl;
        for(int i=0;i<M;i++)
        {
            cin>>temp;
            X.push_back(temp);
        }
        cout<<"enter values of second array : "<<endl;
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            Y.push_back(temp);
        }
        sort(Y.begin(),Y.end());
        long long int count=0;
        int ZERO=0,TWO=0,THREE=0,FOUR=0,ONE=0;
        for(auto i:Y)
        {
            if(i==0)ZERO++;
            if(i==2)TWO++;
            if(i==1)ONE++;
            if(i==3)THREE++;
            if(i==4)FOUR++;
        }
        for(int i=0;i<M;i++)
        {
            if(X[i]==0){}
            else if(X[i]==1){count+=ZERO;}
            else
            {
                int index=binary_search(Y,0,N-1,X[i]);
                count+=ONE;
                if(index==-1);
                else
                {
                    count+=N-index;
                    if(X[i]==2)
                    {
                        count-=THREE;
                        count-=FOUR;
                    }
                    if(X[i]==3)
                    {
                        count+=TWO;
                    }
                }
            }
		} 
        cout<<"No of Pairs : ";
        cout<<count<<endl;
    }
	
	return 0;
}
