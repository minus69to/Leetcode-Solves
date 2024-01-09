#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int nrow = matrix.size();
        int ncol = matrix[0].size();

        int c0 = 1;
        for (int r = 0; r < nrow; r++)
        {
            for (int c = 0; c < ncol; c++)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[r][0] = 0;

                    if (c != 0)
                    {
                        matrix[0][c] = 0;
                    }
                    else
                    {
                        c0 = 0;
                    }
                }
            }
        }

        for (int i = 1; i < nrow; i++)
        {
            for (int j = 1; j < ncol; j++)
            {
                if (matrix[i][j] != 0)
                {
                    // check for col & row:
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int c = 0; c < ncol; c++)
            {
                matrix[0][c] = 0;
            }
        }

        if (c0 == 0)
        {
            for (int r = 0; r < nrow; r++)
            {
                matrix[r][0] = 0;
            }
        }

        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};

    return 0;
}