#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
      freopen("inputtest.txt","r",stdin);
      freopen("outputtest.txt","w",stdout);
      #endif
//   int n,mini=101;
int t;
cin>>t;
while(t--){
   int ndigits=0;
int n;
cin>>n;
if(n==1){
   int num;
   cin>>num;
   if(num%2==0){
      cout<<"2"<<endl;
      continue;
   }
   else{
      cout<<"1"<<endl;
      continue;
   }
}
string number;
if(n%2==0){
   ndigits=1;
}
cin>>number;
int countoonodd=0,counteoneven=0;
for(int i=0;i<n;i++){
int temp=(int)number[i];
   if((i+1)%2==0){
      if(temp%2==0)
      counteoneven++;
   }else{
      if(temp%2!=0)
      countoonodd++;
   }
}
// cout<<" count on odd"<<countoonodd<<endl;
// cout<<" count on even"<<counteoneven<<endl;

if(counteoneven && ndigits==1){
   cout<<"2";
}
else if(counteoneven==0 && ndigits==1){
cout<<"1";
}
 if(countoonodd && ndigits==0){
   cout<<"1";
}
else if(countoonodd==0&&ndigits==0){
   cout<<"2";
}
cout<<endl;
}
 return 0;

}
