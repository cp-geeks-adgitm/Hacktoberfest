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
vector<int> depth;
int l;
int timer;
 
void dfs( int node , int parent )
{ 
   up[node][0]=parent;
   for(int i=1;i<=l;i++)
   {     
         if( up[node][i-1]!=-1)
            up[node][i]=up[ up[node][i-1] ][i-1];
   }
   tin[node]=timer++;
   for(auto ele : adj[node] )
   {
      if(ele!=parent)
      {
         depth[ele]=depth[node]+1;
         dfs(ele,node);
      }
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
           if( up[u][i]==-1)
                    continue;
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
   depth.resize(n);
   tin.resize(n);
   tout.resize(n);
   int edges;
   edges=n-1;//incase of tree
   while(edges--)
   {
      int a,b;
      cin >> a >> b;
      a--;
      b--;
      adj[a].pb(b);
      adj[b].pb(a);
   }
   depth[0]=0;
   timer=0;
   dfs(0,-1);
   while(q--)
   {
       int a,b;
       cin >> a >> b;
       a--;
       b--;
       int node=LCAquery(a,b);
       int ans=depth[a]+depth[b]-2*depth[node];
       cout << ans << "\n";
   }
}
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   preprocess();
}
