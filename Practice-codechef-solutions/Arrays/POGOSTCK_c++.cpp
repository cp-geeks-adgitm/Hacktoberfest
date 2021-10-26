#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,n,i,j,k;
cin>>t;
for(i=0;i<t;i++)
{
int temp,sum=0,max;
cin>>n;
cin>>k;
int arr[n];
for(j=0;j<n;j++)
cin>>arr[j];
max=arr[n-1];
for(j=0;j<k;j++)
{
sum=0;
temp=n-1-j;
while(temp>=0)
{
sum=sum+arr[temp];
if(sum>max)
max=sum;
temp=temp-k;
}
}
cout<<max<<endl;
}
return 0;
}
