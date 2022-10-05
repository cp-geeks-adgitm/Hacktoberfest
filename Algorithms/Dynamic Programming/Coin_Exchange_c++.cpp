#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int Coin_Exchange_Rec(int S[], int n, int m){
        if(n == 0){
            return 1;
        }

        if(m == 0){
            return 0;
        }

        if(S[m-1] <= n){
            return Coin_Exchange_Rec(S, n-S[m-1], m) + Coin_Exchange_Rec(S, n, m-1);
        }else{
            return Coin_Exchange_Rec(S, n, m-1);
        }
    }

    long long int Coin_Exchange_DP(int S[], int n, int m){
        int t[m+1][n+1];
        for(int i=0; i<n+1; i++){
            t[0][i] = 0;
        }
        for(int i=0; i<m+1; i++){
            t[i][0] = 1;
        }

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(S[i-1] <= j){
                    t[i][j] = t[i][j - S[i-1]] + t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[m][n];
    }
};

int main() {
    int n, m;
    cout<<"Enter value of N cents: ";
    cin>>n;
    cout<<endl;

    cout<<"Enter numbers of coins: ";
    cin>>m;
    cout<<endl;

    int arr[m];
    cout<<"Enter value of m coins: ";
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }
    Solution obj;

    long long int ans = obj.Coin_Exchange_Rec(arr, n, m);
    cout<<"Answer (Recursion) is: "<<ans<<endl;

    long long int ans_dp = obj.Coin_Exchange_DP(arr, n ,m);
    cout<<"Answer (DP) is: "<<ans_dp<<endl;
    return 0;
}
