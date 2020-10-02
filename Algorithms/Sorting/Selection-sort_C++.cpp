#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("inputtest.txt","r",stdin);
    freopen("outputtest.txt","w",stdout);
    #endif

vector<int> arr;
int n;
cin>>n;
for(int i=0;i<n;i++){
int x;
cin>>x;
arr.push_back(x);
}

for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(arr[i]>arr[j]){
   int temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
cout<<"The sorted array is\n";
for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
}

    return 0;

}
