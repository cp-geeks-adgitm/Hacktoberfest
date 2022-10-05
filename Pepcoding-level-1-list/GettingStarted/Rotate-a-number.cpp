#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    long long int n, k;
    cin >> n >> k;
    if (k >= n)
    {
        k = k % n;
    }
    long long int x = n, c = 0;
    while (x != 0)
    {
        c++;
        x /= 10;
    }
    long long int t = 1;
    long long int m = c - 1;
    while (m--)
    {
        t *= 10;
    }
    if (k > 0)
    {
        while (k--)
        {
            long long int p = n % 10;
            n /= 10;
            n = p * t + n;
        }
    }
    else
    {
        while (k++)
        {
            long long int q = n / t;
            n = n % t;
            n = n * 10 + q;
        }
    }
    cout << n << endl;

    //write your code here
}