#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    long long int t = 10;
    int x = n, c = 0;
    while (x != 0)
    {
        c++;
        x /= 10;
    }
    while (c--)
    {
        cout << ((n % t) * 10 / t) << endl;
        t *= 10;
    }
    //write your code here
}