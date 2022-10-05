#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> res;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < v[i])
        {
            st.pop();
        }
        res.push_back(st.empty() ? i + 1 : i - st.top().second);
        st.push({v[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}