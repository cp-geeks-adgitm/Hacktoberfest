#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=1;
        for(int i=0;i<n-1;i++){
            if (arr[i]>=arr[i+1]){
                count++;
            }
            else{
                arr[i+1]=arr[i];
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
