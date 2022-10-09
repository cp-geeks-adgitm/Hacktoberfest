#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=2e5+7;
const int mod=1e9+7;
const double eps=1e-6;
const double pi=    3.14159265358979323846;
using namespace std;  
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;
 
vector<int> adj[N];
vector<int> vec[N];
vector<int> ans;
vector<int> subtree;
vector<int> vals;
map<int,int> freq;
int distinct;
 
void update(int value,int type)
{
    if(type==1)
    {
        if(freq.find(value)==freq.end())
                distinct++;
        freq[value]++;
    }
    else
    {
        freq[value]--;
        if(freq[value]==0)
        {
            freq.erase(value);
            distinct--;
        }
    }
}
void dfs_size(int node,int parent)
{
    subtree[node]=1;
    for(auto ele : adj[node])
    {
        if(ele!=parent)
        {
            dfs_size(ele,node);
            subtree[node]+=subtree[ele];
        }
    }
}
 
void dfs(int node,int parent,bool keep)
{
    int mx=-1;
    int bigChild=-1;
    for(auto ele : adj[node] )
    {
        if(ele!=parent)
        {
            if(subtree[ele]>mx)
            {
                mx=subtree[ele];
                bigChild=ele;
            }
        }
    }
 
    for(auto ele : adj[node] )
    {
        if(ele!=parent && ele!=bigChild)
            dfs(ele,node,0);
    }
 
    if(bigChild!=-1)
    {
        dfs(bigChild,node,1);
        swap(vec[bigChild],vec[node]);
    }
 
    vec[node].pb(node);
    update(vals[node],1);
    for(auto ele : adj[node] )
    {
        if(ele==parent || ele==bigChild)
                continue;
        for(auto u : vec[ele] )
        {
            update(vals[u],1);
            vec[node].pb(u);
        }
    }
    //cout << node << " " << parent << " " << bigChild << endl;
    ans[node]=distinct;
 
    if(keep==0)
    {
        for(auto ele : vec[node] )
                update(vals[ele],-1);
    }
}
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
 
   int n;
   cin >> n;
 
   subtree.resize(n);
   ans.resize(n);
   vals.resize(n);
 
   for(int i=0;i<n;i++)
        cin >> vals[i];
 
   for(int i=1;i<n;i++)
   {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
   }
 
   dfs_size(0,-1);
   distinct=0;
   dfs(0,-1,0);
 
   for(auto ele : ans)
        cout << ele << " ";
}
