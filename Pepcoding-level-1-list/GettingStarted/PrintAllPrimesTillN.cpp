#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000001];
    memset(a, 0, sizeof(a));
    for (int i = 2; i <= sqrt(1e6); i++)
    {
        if (a[i] == 0)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {

                a[j] = 1;
            }
        }
    }
    int l, h;
    cin >> l >> h;
    for (int i = l; i <= h; i++)
    {
        if (!a[i])
        {
            cout << i << endl;
        }
    }
    return 0;
}
