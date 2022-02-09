// Implement Framing technique - Bit Stuffing

#include<iostream>
#include<vector>
using namespace std;

vector<int>bitStuffing(vector<int>arr)
{
	int n = arr.size();
	vector<int>res;
	
	int i=0;
	
	while(i<n)
	{
		while(i<n and arr[i] == 0)
		{
			res.push_back(0);
			i++;
		}
		
		int count = 0;
		while(i<n and arr[i] == 1 and count<5)
		{
			res.push_back(1);
			i++;
			count++;
		}
		
		if(count==5)
		{
			res.push_back(0);
		}
		
	}
	
	return res;
}

int main()
{
	int n;
	cout<<"Enter the no. of elements in the array: ";
	cin>>n;
	
	vector<int>arr(n);
	cout<<"Enter the elements of the array:\n";
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	vector<int>res = bitStuffing(arr);
	cout<<"The array after Bit Stuffing is:\n";
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<" ";
	}
}