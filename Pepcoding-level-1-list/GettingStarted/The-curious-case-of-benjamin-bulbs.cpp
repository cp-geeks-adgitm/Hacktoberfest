#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int i = 1;
    while ((i * i) <= n)
    {
        cout << (i * i) << endl;
        i++;
    }
    //write your code here
}