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
   int n,k;
   cin>>n>>k;
   string s;
   vector<int> a;
cin>>s;
int x=0,c=0;
   for(int i=0;i<s.length();i++){
      if( s[i]=='0'&&s[i+1]=='0'&& i+1<n){
          c++;
        }

       if(s[i]=='0' && s[i+1]=='1' &&i+1<n){
         //x++;
         c++;
         if(c!=0)
         a.push_back(c);
      }
      else if(s[i]=='1' && s[i+1]=='0' && i+1<n){
         //x++;
         if(c!=0)
         a.push_back(c);

      }

   }
   int d=0;
   sort(a.begin(),a.end());
   for(int i=0;i<a.size()-(k/2);i++){
      d+=a[i];
   }
   cout<<d<<" ";
   // x -=k;
   // if(x<0){
   //    x=0;
   // }
   // cout<<x;
   cout<<endl;

}

 return 0;

}
