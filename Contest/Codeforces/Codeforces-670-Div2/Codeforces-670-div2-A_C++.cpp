#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
      freopen("inputtest.txt","r",stdin);
      freopen("outputtest.txt","w",stdout);
      #endif
int t;
cin>>t;
while(t--){
   int n;
   cin>>n;
   vector<int> v(n);
int a[101]={0};

for(int i=0;i<n;i++){
   cin>>v[i];
}
int miss=0,min1=INT_MAX,min2=INT_MAX;
sort(v.begin(),v.end());
if(v[0]==0){
   miss++;
}
for(int i=0;i<n;i++){
a[v[i]]++;
}
int i=0;
for(;i<101;i++){
   if(a[i]<2){
      min1=i;
      break;
   }
}
for(;i<101;i++){
   if(a[i]<1){
      min2=i;
      break;
   }
}

   cout<<min1+min2;
cout<<endl;
}
 return 0;

}
