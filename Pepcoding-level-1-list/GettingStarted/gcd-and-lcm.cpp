#include <iostream>
using namespace std;
int gcdfind(int num1, int num2)
{
    if (b == 0)
    {
        return a;
    }
    return gcdfind(b, a % b);
}
int main(int argc, char **argv)
{
    int num1, num2;
    cin >> num1 >> num2;
    int gcd = gcdfind(num1, num2);
    //write your code here
    cout << gcd << endl;
    int lcm = (num1 * num2) / gcd;

    cout << lcm << endl;
}