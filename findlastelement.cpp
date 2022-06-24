#include<iostream>
using namespace std;
int vidx,n;
int arr[10000],m;
int lastindex(int arr[],int vidx,int n,int m)
{
	if(vidx==n)
	{
		return -1;
	}
	int rr=lastindex(arr,vidx+1,n,m);
	if((arr[vidx]==m) && (rr==-1))
	{
		return vidx;
	}
	else
	{return rr;}
}
int main() {
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	int x=lastindex(arr,0,n,m);
	cout<<x;

	return 0;
}
