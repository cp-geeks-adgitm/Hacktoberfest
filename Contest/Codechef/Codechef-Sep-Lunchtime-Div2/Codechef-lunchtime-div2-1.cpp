#include <bits/stdc++.h>
using namespace std;





int main() {
   #ifndef ONLINE_JUDGE
      freopen("inputtest.txt","r",stdin);
      freopen("outputtest.txt","w",stdout);
      #endif
int t;
cin>>t;
while(t--){
int n;
cin>>n;
int A[n+1];
for(int i=1;i<=n;i++){
   cin>>A[i];
}
int d=0;
for(int i=1;i<=n;i++){
   int f=0;
   if(A[i]==i){
      continue;
   }
   else{
      for(int j=i-1;j>=1;j--){
         if(__gcd(i,j)==A[i]){
         f=1;
         break;
      }
      }
      if(f==0){
         cout<<"NO"<<endl;
         d=1;
         break;
      }
   }
}
if(d==0){
   cout<<"YES"<<endl;
}

}

  return 0;

}
