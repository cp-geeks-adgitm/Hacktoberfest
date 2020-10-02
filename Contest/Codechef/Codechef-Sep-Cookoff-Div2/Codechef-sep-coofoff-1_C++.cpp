#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
      freopen("inputtest.txt","r",stdin);
      freopen("outputtest.txt","w",stdout);
      #endif
      // int s;
      // cin>>s;
int t;

cin>>t;

while(t--){
   int n,k,l;
   cin>>n>>k>>l;
   if(k==1&&n>1){
      cout<<"-1"<<endl;
      continue;
   }

   if(n>(l*k)){
      cout<<"-1"<<endl;
      continue;
   }
   int x=1;
   while(n--){
      if(x>k){
      x=1;
   }

      cout<<x<<" ";

      x++;
   }
   cout<<endl;

}

 return 0;

}
