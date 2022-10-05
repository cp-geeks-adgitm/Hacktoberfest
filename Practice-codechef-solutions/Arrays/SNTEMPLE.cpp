
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    long long int ele[n],maxH;
    cin>>ele[0];
    long long int sum = ele[0];
    if(ele[0]>1)
        ele[0] = 1;
    for(int i=1;i<n;i++){
        long long int temp;
        cin>>temp;
        sum+=temp;
        if(temp > ele[i-1]+1)
            ele[i] = ele[i-1]+1;
        else
            ele[i] = temp;
    }
    
    ele[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(ele[i] > ele[i+1]+1)
            ele[i] = ele[i+1]+1;
         maxH = max(ele[i],maxH);
    }
    
    cout<<sum-(maxH*maxH)<<endl;
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
