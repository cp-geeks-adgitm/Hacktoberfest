/* 
Leetcode Question #54
url - https://leetcode.com/problems/spiral-matrix/
Coded by - Shadman Afzal
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> result;

        int a = 0, b = 0, c = matrix.size() - 1, d = matrix[0].size() - 1;

        while (a <= c and b <= d)
        {
            for (int i = b; i <= d; i++)
            {
                result.push_back(matrix[a][i]);
            }
            a++;

            for (int i = a; i <= c; i++)
                result.push_back(matrix[i][d]);
            d--;

            if (a <= c)
            {
                for (int i = d; i >= b; i--)
                    result.push_back(matrix[c][i]);
                c--;
            }

            if (b <= d)
            {
                for (int i = c; i >= a; i--)
                    result.push_back(matrix[i][b]);
                b++;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol = Solution();
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    vector<int> result = sol.spiralOrder(matrix);

    for (int i : result)
    {
        cout << i << " ";
    }
}