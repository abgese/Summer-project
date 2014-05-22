#include<iostream>
using namespace std;
void isort(int a[],int low,int high)
{
	int i,j,t;
	for(i=low;i<high;i++)
	{
		if(a[i]>a[i+1])
		{
			t=a[i+1];
			for(j=i;a[j]>t&&j>=low;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=t;
		}
	}
}
void merge(int a[],int low,int high,int mid)
{
	int c[high-low+1];
	int i=low;
	int j=mid+1;
	int k=0;
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
}
void sort(int a[],int low,int high)
{
	int n=high-low;
	if(n<=15)
	isort(a,low,high);
	else
	{
    int mid=(low+high)/2;
		sort(a,low,mid);
		sort(a,mid+1,high);
		merge(a,low,high,mid);
	}
}
int main()
{
	int n,i;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int a[n];
	cout<<"Enter the array :\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,0,n-1);
	cout<<"The sorted array :\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
