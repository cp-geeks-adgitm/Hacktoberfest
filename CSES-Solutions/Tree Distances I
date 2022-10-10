#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=2e5+7;
const int mod=998244353;
const double eps=1e-6;
using namespace std;  
 
vector<int> adj[N];
vector<int> distroot;
vector<int> distn1,distn2;
 
void dfs1( int node , int parent )
{
    for(auto ele : adj[node])
    {
        if(ele==parent)
                continue;
        distroot[ele]=distroot[node]+1;
        dfs1(ele,node);
    }
}
void dfs2( int node , int parent )
{
    for(auto ele : adj[node])
    {
        if(ele==parent)
                continue;
        distn1[ele]=distn1[node]+1;
        dfs2(ele,node);
    }
}
void dfs3( int node , int parent )
{
    for(auto ele : adj[node])
    {
        if(ele==parent)
                continue;
        distn2[ele]=distn2[node]+1;
        dfs3(ele,node);
    }
}
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;
   for(int i=1;i<n;i++)
   {
       int a,b;
       cin >> a >> b;
       a--;
       b--;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   
   distroot.resize(n);
   distn1.resize(n);
   distn2.resize(n);
   
   distroot[0]=0;
   dfs1(0,-1);
   int a=0;
   for(int i=0;i<n;i++)
   {
       if( distroot[i] > distroot[a] )
            a=i;
   }
   
   distn1[a]=0;
   dfs2(a,-1);
   int b=0;
   for(int i=0;i<n;i++)
   {
       if( distn1[i] > distn1[b] )
            b=i;
   }
   //cout << a << " " << b << "\n";
   distn2[b]=0;
   dfs3(b,-1);
   
   for(int i=0;i<n;i++)
        cout << std::max( distn1[i] , distn2[i] ) << " ";
}
