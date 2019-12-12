//we need to find an element in an array of size n which occurs more than n/2 times, it is also called as majority element.
//atmost only one majority element can be present in an array.
//Algorithm :
// step 1 : find a candidate for majority element.
// step 2 : check if it is the majority element or not.
// Time complexity : O(n) 
// Space complexity : O(1)
// steps for finding candidate :
//    step 1 : initialize count of current candidate as 0 -> count = 0
//    step 2 : iterate over the array and do following steps :
//             a) if count == 0 , set the current element as candidate i.e candidate = array[i] and count = 1
//             b) else 
//                        if candidate ==  array[i]
//                           set count = count+1
//                        else 
//                           set count = count-1
#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        // size of the array.
        cin>>n;
        vector<int>array(n);
        for(int i=0;i<n;i++)
        {
           cin>>array[i];
        }
        //Moore's voting algorithm implementation
        int count=0,candidate;
        for(int i=0;i<n;i++)
        {
          if(count==0){candidate=array[i];count=1;}
          else
          {   
            if(candidate==array[i])count++;
            else count--;
          }
        }
        count =0;
        for(int i=0;i<n;i++)
        {
          if(candidate==array[i])count++;
        }
        if (count>n/2) cout<<"candidate is :"<<array[candidate]<<endl;
        else cout<<"no candidate";
}
