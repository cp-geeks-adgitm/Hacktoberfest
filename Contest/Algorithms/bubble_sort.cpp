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

for(int i=0;i<n/2;i++){
for(int j=0;j<n-1;j++){
if(arr[j]>arr[j+1]){
   int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
cout<<"The sorted array is\n";
for(int i=0;i<n;i++){
   cout<<arr[i]<<" ";
}

    return 0;

}
