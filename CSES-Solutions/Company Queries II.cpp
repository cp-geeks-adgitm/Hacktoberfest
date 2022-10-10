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
vector<int> tin;
vector<int> tout;
int l;
int timer;
 
void dfs( int node , int parent )
{ 
   up[node][0]=parent;
   for(int i=1;i<=l;i++)
         up[node][i]=up[ up[node][i-1] ][i-1];
   tin[node]=timer++;
   for(auto ele : adj[node] )
   {
      if(ele!=parent)
         dfs(ele,node);
   }
   tout[node]=timer++;
}
 
bool is_ancestor(int u,int v)
{
   return tin[u]<=tin[v] && tout[u]>=tout[v];
}
 
int LCAquery(int u,int v)
{
      if( is_ancestor(u,v) )
            return u;
      if( is_ancestor(v,u) )
            return v;
      for(int i=l;i>=0;i--)
      {
           if (!is_ancestor(up[u][i], v))
           {
                u = up[u][i];
           }
      }
      return up[u][0];
}
 
void preprocess()
{
   int n,q;
   cin >> n >> q;
   l=ceil(log2(n));
   up.resize(n,vector<int>(l+1));
   tin.resize(n);
   tout.resize(n);
   int edges;
   edges=n-1;//incase of tree
   //cin >> edges;
   for(int i=1;i<n;i++)
   {
       int a;
       cin >> a ;
       a--;
       adj[a].pb(i);//directed graph
   }
   timer=0;
   dfs(0,0);
   while(q--)
   {
       int a,b;
       cin >> a >> b;
       a--;
       b--;
       cout << LCAquery(a,b)+1 << "\n";
   }
}
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   preprocess();
}
