#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin>>T;
    while(T--) 
	{
        int N, S = 0, mx = INT_MIN;
        cin>>N;

        while(N--) 
		{
            int a;
            cin>>a;
            S += a;
            mx = max(mx, S);
            if (S < 0)
                S = 0;
        }
        cout<<mx<<endl;
    }
}
