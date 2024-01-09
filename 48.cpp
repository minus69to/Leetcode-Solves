#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int length = matrix.size(), k = 0;

        for (int i = 0; i < length / 2; i++)
        {
            for (int j = 0; j < length - 1 - i - k; j++)
            {
                swap(matrix[i][0 + i + j], matrix[i + j][length - 1 - i]);
                swap(matrix[length - 1 - i][length - 1 - i - j], matrix[length - 1 - i - j][0 + i]);
                swap(matrix[i][0 + i + j], matrix[length - 1 - i][length - 1 - i - j]);
            }
            k++;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution sol;
    sol.rotate(matrix);

    for (auto x : matrix)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}