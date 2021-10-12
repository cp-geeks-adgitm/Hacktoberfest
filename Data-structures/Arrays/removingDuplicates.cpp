#include<iostream>
using namespace std;
int removeDuplicates(int a[] , int n)
{
  if(n==1||n==0)
    return n;
  int temp[n];
  int j=0;
  for(int i=0;i<n-1;i++)
  {
    if(a[i]!=a[i+1])
      temp[j++]=a[i];
  }
  temp[j++]=a[n-1];
  for(int i=0;i<n;i++)
    a[i]=temp[i];
  
  return j;
}

int main()
{
  int n;
  cout<<"Enter size:";
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
   
  int N=removeDuplicates(arr,n);
  for(int i=0;i<n;i++)
  {
      if(arr[i]!=0)
      cout<<arr[i]<<" ";
  }
    
  return 0;
}
