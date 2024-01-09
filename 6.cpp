#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        
        vector<string> vec;
        for (int i = 0; i < numRows; i++)
        {
            vec.push_back("");
        }

        int length = s.size();
        int comparetor = 0;
        --numRows;

        int i = 0, flag = 0;
        while (i < length)
        {
            vec[comparetor] = vec[comparetor] + s[i];

            if ((numRows - comparetor) == numRows)
            {

                flag = 1;
            }
            else if ((numRows - comparetor) == 0)
            {

                flag = 0;
            }

            if (flag == 1)
            {
                comparetor++;
            }
            else if (flag == 0)
            {
                comparetor--;
            }

            i++;
        }

        string ans = "";
        for (auto x : vec)
        {
            ans = ans + x;
        }

        return ans;
    }
};

int main()
{
    string s = "ab";
    int numRows = 1;

    Solution sol;
    cout << sol.convert(s, numRows);

    return 0;
}