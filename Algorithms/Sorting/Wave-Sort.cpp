#include <iostream>
using namespace std;

// Function to swap the number
void swap(int a[],int i,int j)
{ int temp=a[i];
    
	a[i]=a[j];
    
	a[j]=temp;
}
void wavesort(int a[],int n)
{ 
	for(int i=1;i<n;i+=2)
    
	{ if(a[i]>a[i-1])
        
		swap(a,i,i-1);
        
		if(a[i]>a[i+1] && i<=n-2)
        
		swap(a,i,i+1);
    }
}
int main() {
	
	int a[]={10, 90, 49, 2, 1, 5, 23};
	
	int n=sizeof(a)/sizeof(a[0]);
	
	wavesort(a,n);
	
	for(int i=0;i<n;i++)
	
	cout<<a[i]<<" ";
	
	return 0;
}
