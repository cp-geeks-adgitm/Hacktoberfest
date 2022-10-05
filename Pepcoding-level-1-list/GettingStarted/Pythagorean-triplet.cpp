#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a * a + b * b) == (c * c))
    {
        cout << "true";
    }
    else if ((c * c + b * b) == (a * a))
    {
        cout << "true";
    }
    else if ((a * a + c * c) == (b * b))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    //write your code here
}