#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> umap;
        int length = 0, l = 0, f = 0;

        while (f < s.size())
        {

            if (umap.find(s[f]) == umap.end())
            {
                l = l; // Same
            }
            else if (umap.find(s[f]) != umap.end() && l > umap[s[f]])
            {
                l = l; // Same
            }
            else if (umap.find(s[f]) != umap.end() && l <= umap[s[f]])
            {
                l = umap[s[f]] + 1; // Different
            }

            umap[s[f]] = f;
            f++;
            length = max(length, f - l);
            // cout << "Length-> " << length << endl;
        }

        return length;
    }
};

int main()
{

    // string s = "abcabcbbcdefgb";
    // string s = "pwwkew";
    // string s = "aaa";
    string s = "aab";

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}