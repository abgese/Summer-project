#include<iostream>
using namespace std;
void isort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			t=a[i+1];
			for(j=i;a[j]>t&&j>=0;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=t;
		}
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
	isort(a,n);
	cout<<"The sorted array :\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
