#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

bool isdigit(char c)
{
    return c >= '0' && c <= '9';
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '^')
    {
        return 3;
    }
    if (c == '=')
    {
        return 4;
    }
    if (c == '(')
    {
        return 5;
    }
    // ^ - 3
    // unary operators - 4
    // (,) - 5
}

int compute(int x, int y, char c)
{
    if (c == '+')
    {
        return x + y;
    }
    if (c == '-')
    {
        return x - y;
    }
    if (c == '*')
    {
        return x * y;
    }
    if (c == '/')
    {
        return x / y;
    }
}

int evaluate(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                x = y + x;
                break;
            case '-':
                x = y - x;
                break;
            case '/':
                x = y / x;
                break;
            case '*':
                x = y * x;
                break;

            default:
                break;
            }
            st.push(x);
        }
    }
    return st.top();
}

string infix(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            string x;
            x += s[i];
            st.push(x);
        }

        else
        {
            string x = st.top();
            st.pop();
            string y = st.top();
            st.pop();

            st.push('(' + y + s[i] + x + ')');
        }
    }
    return st.top();
}

string prefix(string s)
{
    stack<char> st;
    string pre;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {
            pre += s[i];
        }
        else if (s[i] == ')')
        {

            while (!st.empty() && st.top() != '(')
            {
                pre += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && precedence(s[i]) <= precedence(st.top()) && st.top() != '(')
                {

                    pre += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && precedence(s[i]) < precedence(st.top()) && st.top() != '(')
                {

                    pre += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {

        pre += st.top();
        st.pop();
    }
    return pre;
}
int main()
{
    string s;
    getline(cin, s);
    int x = evaluate(s);

    cout << x << endl;
    s = infix(s);
    cout << s << endl;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            s[i] = '(';
        }
        else if (s[i] == '(')
        {
            s[i] = ')';
        }
    }
    string y = prefix(s);
    reverse(y.begin(), y.end());

    cout << y << endl;
    return 0;
}