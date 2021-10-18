#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

vector<long long int> solve(vector<long long int> v, int n, int k)
{
    queue<long long int> q;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && q.front() <= v[i])
        {
            q.pop();
        }
        q.push(v[i]);
    }
    
    vector<long long int> res;
    res.push_back(q.front());
    for (int i = k; i < n; i++)
    {
        if (q.size() == k)
        {
            q.pop();
            while (!q.empty() && q.front() <= v[i])
            {
                q.pop();
            }
            if (q.empty())
            {
                res.push_back(v[i]);
            }
            else
            {
                res.push_back(q.front());
            }
        }
        else
        {
            while (!q.empty() && q.front() <= v[i])
            {
                q.pop();
            }
            if (q.empty())
            {
                res.push_back(v[i]);
            }
            else
            {
                res.push_back(q.front());
            }
        }
        q.push(v[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> v;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    vector<long long int> r = solve(v, n, k);
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    return 0;
}

//2nd approach
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

vector<long long int> solve(vector<long long int> v, int n, int k)
{
    deque<long long int> q;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && v[q.back()] <= v[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    vector<long long int> res;
    res.push_back(v[q.front()]);
    for (int i = k; i < n; i++)
    {
        if (!q.empty() && i - k == q.front())
        {
            q.pop_front();
            while (!q.empty() && v[q.back()] <= v[i])
            {
                q.pop_back();
            }
            if (q.empty())
            {
                res.push_back(v[i]);
            }
            else
            {
                res.push_back(v[q.front()]);
            }
        }
        else
        {
            while (!q.empty() && v[q.back()] <= v[i])
            {
                q.pop_back();
            }
            if (q.empty())
            {
                res.push_back(v[i]);
            }
            else
            {
                res.push_back(v[q.front()]);
            }
        }
        q.push_back(i);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> v;
    for (int i = 0; i < n; i++)
    {
        long long int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    vector<long long int> r = solve(v, n, k);
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    return 0;
}
