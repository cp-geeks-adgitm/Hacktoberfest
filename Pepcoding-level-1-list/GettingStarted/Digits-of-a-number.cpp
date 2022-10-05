#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int t = n, c = 0;
    while (t != 0)
    {
        t /= 10;
        c++;
    }
    long long int x = 1;
    while (c != 1)
    {
        x = x * 10;
        c--;
    }
    while (x != 0)
    {
        cout << n / x << endl;
        n = n % x;
        x /= 10;
    }

    //write your code here
}
