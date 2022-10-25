#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin >> n;
    ll cnt=0;
    for(ll i=1;i<n;i++){
    	if(pow(5,i)<=n){
    		cnt+=n/pow(5,i);
    	}
    	else{
    		break;
    	}
    }
    cout << cnt << endl;
}
