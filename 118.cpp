#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> matrix;
        // matrix.push_back({1});

        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(matrix[i - 1][j - 1] + matrix[i - 1][j]);
                }
            }
            matrix.push_back(temp);
        }

        return matrix;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = sol.generate(10);


    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}