#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }
    for (int i = 3; n != 1; i += 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    //write your code here
}
