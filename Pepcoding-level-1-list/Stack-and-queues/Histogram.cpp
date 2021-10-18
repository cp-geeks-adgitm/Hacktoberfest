//First approach

#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> v, int n)
{
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = i - 1, h = i + 1;
        while (l >= 0 && v[l] >= v[i])
        {
            l--;
        }
        while (h < n && v[h] >= v[i])
        {
            h++;
        }

        area = max(area, v[i] * (h - l - 1));
    }
    return area;
}
int main()
{
    vector<int> v{2, 1, 5, 6, 2, 3, 1};
    int x = solve(v, v.size());
    cout << x;
    return 0;
}

//Second approach

#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int solve(vector<int> v, int n)
{
    vector<int> l(n, 0), r(n, 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().first >= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            l[i] = -1;
        }
        else
        {
            l[i] = s.top().second;
        }
        s.push({v[i], i});
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first >= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            r[i] = n;
        }
        else
        {
            r[i] = s.top().second;
        }
        s.push({v[i], i});
    }
    int area;
    for (int i = 0; i < n; i++)
    {
        area = max(area, (r[i] - l[i] - 1) * v[i]);
    }
    return area;
}
int main()
{
    vector<int> v{2, 1, 5, 6, 2, 3, 1};
    int x = solve(v, v.size());
    cout << x;
    return 0;
}
