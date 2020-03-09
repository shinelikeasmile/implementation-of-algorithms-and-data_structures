#include <bits/stdc++.h>
using namespace std;
struct Item
{
	int value;
	int weight;
	Item(int value,int weight):value(value),weight(weight){}
}; 
bool compare(struct Item Item1,struct Item Item2)
{
	double R1=(double)Item1.value/Item1.weight;
	double R2=(double)Item2.value/Item2.weight;
	return R1>R2;
}
double fractionalknapsack(int W,struct Item arr[],int n)
{
	sort(arr,arr+n,compare);
	int curweight=0;
	double value=0.0;
	for(int i=0;i<n;i++)
	{
		if(curweight+arr[i].weight<=W)
		{
			curweight+=arr[i].weight;
			value+=arr[i].value;
		}
		else
		{
			int neededweight=W-curweight;
			value+=arr[i].value*((double)neededweight/arr[i].weight);
			break;
		}
	}
	return value;
}
int main()
{
	int W=50;
	Item arr[]={{60,10},{100,20},{120,30}};
	cout<<fractionalknapsack(W,arr,3);
	
}
