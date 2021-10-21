#include <iostream>
using namespace std;


int main()
{
    // your code goes here
    int tweet, click;
    cin >> tweet >> click;
    int a[tweet] = {0};
    for (int i = 0; i < click; i++)
    {
        string s;
        int n;
        cin >> s;

        if (s == "CLOSEALL")
        {
            for (int k = 0; k < tweet; k++)
                a[k] = 0;
        }
        else
        {
            cin >> n;

            if (a[n - 1] == 0)
                a[n - 1] = 1;
            else
                a[n - 1] = 0;
        }

        int sum = 0;
        for (int k = 0; k < tweet; k++)
        {
            sum += a[k];
        }
        cout << sum << endl;
    }
    return 0;
}
