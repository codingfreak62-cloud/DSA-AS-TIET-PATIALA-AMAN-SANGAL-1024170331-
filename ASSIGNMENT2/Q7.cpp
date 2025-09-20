#include<iostream>
#include<vector>
using namespace std;
int inversion(vector<int>& arr,int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(i<j && arr[i]>arr[j])
			{
				count++;
			}
		}
	}
	return count;
}
int main(){
	int n;
	cout<<"Enter the value of n: "<<endl;
	cin>>n;
	vector<int> arr(n);
	cout<<"Elements of array are: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int j=0;j<n;j++)
	{
		cout<<arr[j];
	}
	cout<<endl;
	int countvalue=inversion(arr,n);
	cout<<"Number of inversions are "<<countvalue<<endl;
	return 0;
}
