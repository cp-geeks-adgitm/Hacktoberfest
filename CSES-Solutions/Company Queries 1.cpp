#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=2e5+7;
const int mod=1e9+7;
const double eps=1e-6;
const double pi=    3.14159265358979323846;
using namespace std;  
 
  
vector<int> adj[N];
vector<vector<int>> up;
 
void dfs( int node , int parent )
{
    if(parent!=0)
        up[node][0]=parent;
    for(int i=1;i<22;i++)
    {
         int above=up[node][i-1];
         if( above!=-1 )
         {
             up[node][i]=up[above][i-1];
         }
    }
 
    for(auto ele : adj[node] )
    {
        if(ele!=parent)
            dfs(ele,node);
    }
}
  
int LCAquery(int u,int v)
{
     int current=u;
     int left=v;
     for(int i=21;i>=0;i--)
     {
         if( up[ current ][i]!=-1 && (left)>=(1<<i) )
         {
                  current=up[current][i];
                  left-=(1<<i);
         }
     }
     if(left)
         current=-1;
     return current;
}
 
void preprocess()
{
   int n,q;
   cin >> n >> q;
   up.resize( n+1 , vector<int>(22,-1) );
   for(int i=2;i<=n;i++)
   {
      int a;
      cin >> a;
      adj[a].pb(i);
   }  
   dfs(1,0);
   
   while(q--)
   {
       int a,b;
       cin >>  a >> b;
       cout << LCAquery(a,b) << "\n";
   }
}
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   preprocess();
}
