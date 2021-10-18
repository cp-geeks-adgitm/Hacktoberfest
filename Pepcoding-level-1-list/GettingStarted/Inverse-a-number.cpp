#include <bits/stdc++.h>

using namespace std;

bool sortcompare(pair<int,int>& a,pair<int,int>& b){
    return a.second<b.second;
}


int main(int argc, char **argv)
{
    int n;
    cin >> n;
    long long int t = 10;
    int x = n, c = 0,m=0;
    while (x != 0)
    {
        c++;
        x /= 10;
    }
    x = 1;
    m=c;
    pair<int,int> p[c+1];
    c++;
    while (c--)
    {
        p[x].first=x;
        p[x].second=(n % t) * 10 / t;
        t *= 10;
        x++;
    }
    
    sort(p,p+m+1,sortcompare);
    for(int i=m;i>=1;i--){
        cout<<p[i].first;
    }
}