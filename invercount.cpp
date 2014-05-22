#include<iostream>
using namespace std;
int merge(int a[],int low,int high,int mid)
{
	int c[high-low+1];
	int x=0;
	int i=low;
	int j=mid+1;
	int k=0;
	if(low>=high)
	x=0;
	while(i<=mid&&j<=high)
	{
		if(a[i]<=a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			x+=mid-i+1;
			k++;
			j++;
		} 
	}
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	for(i=0;i<k;i++)
	{
		a[low+i]=c[i];
	}
	return x;
}
int sort(int a[],int low,int high)
{
    int mid=(low+high)/2;
	int x=0;
	if(high>low)
	{
		x+=sort(a,low,mid);
		x+=sort(a,mid+1,high);
		x+=merge(a,low,high,mid);
	}
	return x;
}
int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int a[n],x;
	cout<<"Enter the array :\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	x=sort(a,0,n-1);
	cout<<"\nThe number of inversions : "<<x;
}


