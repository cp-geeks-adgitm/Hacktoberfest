#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(signed argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) cin >> ar[i];
        
        if (k <= n){
            for (int i = 0; i < k; i++) ar[i] ^= ar[n-i-1];
            for (int i = 0; i < n; i++) cout << ar[i] << " ";
            cout << endl;
            continue;
        }
        int times[n];
        for (int i = 0; i < n; i++){
            times[i] = (k/n);
            if (i < (k%n)) times[i]++;
        }
        for (int i = 0; i < n/2; i++){
            int j = (n-i-1);
            int timei = min(times[i], times[j]);
            int timej = timei;
            int tot = timei+timej;
            int temp[3] = {ar[i]^ar[j], ar[i], ar[j]};
            tot--;
            ar[j] = temp[tot%3];
            ar[i] = temp[(tot-1)%3];
            if (times[i] == times[j]) continue;
            if (times[j] < times[i]){
                int ll = times[i]-times[j];
                if (ll & 1) ar[i] = ar[i]^ar[j];
            } else {
                int ll = times[j]-times[i];
                if (ll & 1) ar[j] = ar[j]^ar[i];
            }
        }
        if (n & 1) ar[n/2] = 0;
        for (int i = 0; i  < n; i++) cout << ar[i] << " ";
        
        cout << endl;
    }
    return 0;
}
