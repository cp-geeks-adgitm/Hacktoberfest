#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
const int N=2e5+7;
const int mod=998244353;
const double eps=1e-6;
const double pi=	3.14159265358979323846;
using namespace std;  
 
vector<int> adj[N];
int des[N];
int vis[N];
int ans[N];
 
void dfs1(int node , int parent )//to find the number of descendents
{
    des[node]=1;
    for(auto ele : adj[node])
    {
        if(ele!=parent)
        {
                dfs1(ele,node);
                des[node]+=des[ele];
        }
    }
    return;
}
void dfs(int node,int parent)// to find the ans for the root
{
    for(auto child : adj[node])
    {
        if(child != parent)
        {
            vis[child]=vis[node]+1;
            dfs( child , node  );
        }
    }
}
void dfs2(int node,int parent , int n)//to find the ans for each node
{
    for(auto ele : adj[node] )
    {
        if(ele != parent && ele!=0 )
        {
                ans[ele]=0;
                
                ans[ele]=ans[node]+n-2*(des[ele]);
                dfs2( ele , node , n );
        }
    }
}
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   int n;
   cin >> n;
   
   for(int i=0;i<n-1;i++)
   {
       int a,b;
       cin >> a >> b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   
   dfs1(1,-1);
   memset( vis , 0 , sizeof(vis) );
   dfs(1,-1);
   
   memset(ans,0,sizeof(ans));
   for(int i=1;i<=n;i++)
        ans[0]+=vis[i];
 
   ans[1]=ans[0];
   dfs2(1,0,n);
   
   for(int i=1;i<=n;i++)
        cout << ans[i] << "\n";
 
}
