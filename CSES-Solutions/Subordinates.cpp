#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
const int mod=1e9+7;
const int N=2e5+7;
using namespace std;
 
vector<int> adj[N];
bool vis[N];
int ans[N];
 
int dfs(int node)
{
    if(vis[node])
    return ans[node];
    vis[node]=true;
    int juniors=1;
    for(auto junior:adj[node])
        juniors+=dfs(junior);
    ans[node]+=juniors;
    return juniors;
}
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int n;
cin>>n;
for(int i=0;i<n-1;i++)
{
    int ex;
    cin>>ex;
    adj[ex].pb(i+2);
}
 
memset(vis , false , sizeof(vis) );
memset(ans , 0 , sizeof(ans) );
ans[1]=dfs(1);
 
for(int i=1;i<=n;i++)
cout<<ans[i]-1<<" ";
 
}
