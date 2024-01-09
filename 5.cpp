#include <bits/stdc++.h>
using namespace std;

bool compareByValue(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second; // Ascending order
}

class Solution
{
public:
    string longestPalindrome(string s)
    {
        unordered_map<int, int> umap;
        int length = s.size();
        vector<vector<int>> matrix(length, vector<int>(length, 0));

        int k = 1;
        while (k <= length)
        {
            for (int i = 0; i < length; i++)
            {

                if (i + k < length && k <= 1)
                {
                    if (i < length)
                    {
                        if (s[i] == s[i + k])
                        {
                            matrix[i][i + k] = 1;
                            umap[i] = k;
                        }
                    }
                }
                else 
                if (i + k < length && k > 1)
                {
                    if (i < length - 1)
                    {
                        if (s[i] == s[i + k] && matrix[i + 1][i + k - 1] == 1)
                        {
                            matrix[i][i + k] = 1;
                            umap[i] = k;
                        }
                    }
                }

                matrix[i][i] = 1;
            }

            k++;
        }

        vector<pair<int, int>> vec(umap.begin(), umap.end());
        sort(vec.begin(), vec.end(), compareByValue);

        if (length == 0)
        {
            return "";
        }
        else if (vec.size() == 0)
        {
            string ans = s.substr(0, 1);
            return ans;
        }
        else
        {
            string ans = s.substr(vec[0].first, vec[0].second + 1);
            return ans;
        }
    }
};

int main()
{
    string s = "abbcccbbbcaaccbababcbcabca";

    Solution sol;
    cout << sol.longestPalindrome(s);

    return 0;
}