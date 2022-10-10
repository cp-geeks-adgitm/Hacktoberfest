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
 
struct segtree 
{
    const int k=0;//constant will be 0 for operations like sum,max and gcd but for operations like min will iNF
    int size;
    vector< long long > seg;
    
    void init(int n)//initialize the segment tree
    {
        size=1;
        while(size<n)
            size=size*2;
        seg.assign( 2*size , 0 );
    }
    
    long long operation(long long x,long long y)
    {
        return (x+y);
    }    
    void Real_build( vector<long long> &a , int x , int lx , int rx)
    {
        if(rx-lx==1)
        {
            if( lx<(int)a.size() )
                seg[x]=a[lx];
            return;
        }
        int mid=(lx+rx)/2;
        Real_build( a , x*2+1 , lx , mid );
        Real_build( a , x*2+2 , mid , rx );
        seg[x]= operation ( seg[2*x+1],seg[2*x+2] ) ;
    }
    
    void build( vector<long long> &a )
    {
        Real_build(a,0,0,size);
    }
    
    
    void Real_set( int i , int v ,int x , int lx , int rx)
    {
        if(rx-lx==1)//bottom label
        {
            seg[x]=v;
            return;
        }
        int mid=(lx+rx)/2;
        if(i<mid)
            Real_set(i,v,2*x+1,lx,mid);
        else
            Real_set(i,v,2*x+2,mid,rx);
        seg[x]= operation ( seg[2*x+1],seg[2*x+2] ) ;
    }  
    
    void set (int i,int v)
    {
        Real_set(i,v,0,0,size);
    }
    
    long long Real_query( int l , int r , int x , int lx , int rx)
    {
        if( lx>=r || l>=rx)//no intersection
            return k;
        if( lx>=l && rx<=r)
            return seg[x];
        int m=(lx+rx)/2;
        long long s1=Real_query(l,r,2*x+1,lx,m);
        long long s2=Real_query(l,r,2*x+2,m,rx);
        return operation(s1,s2);
    } 
    
    long long query ( int l ,int r)
    {
        return Real_query(l,r,0,0,size);
    }
};
 
vector<ll> val;
vector<int> adj[N];
vector<int> tin,tout;
vector<pair<long long,int>> euler;
int timer;
 
void dfs(int node,int parent)
{
    tin[node]=timer++;
    euler.pb({node,1});
    for(auto ele : adj[node])
    {
        if(ele==parent) 
                continue;
        dfs(ele,node);
    }
    tout[node]=timer++;
    euler.pb({node,-1});    
}
 
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   int n,q;
   cin >> n >> q;
   
   tin.resize(n);
   tout.resize(n);
   val.resize(n);
   
   for(auto &ele : val)
        cin >> ele;
   
   for(int i=0;i<n-1;i++)
   {
       int a,b;
       cin >> a >> b;
       a--;
       b--;
       adj[a].pb(b);
       adj[b].pb(a);
   }
   
   timer=0;
   dfs(0,-1);
   
   int k=euler.size();
   vector<long long> temp(k);
   for(int i=0;i<k;i++)
        temp[i]= val[ euler[i].ff ]*euler[i].ss;
        
   segtree st;
   st.init(k);
   st.build(temp);
 
   while(q--)
   {
       int type;
       cin >> type;
       if(type==1)
       {
           int node;
           cin >> node;
           node--;
           ll value;
           cin >> value;
           st.set(tin[node],value);
           st.set(tout[node],-value);
       }
       else
       {
           int node;
           cin >> node;
           node--;
           cout << st.query(0,tin[node]+1) << "\n";
       }
   }
}
