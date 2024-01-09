#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        int length = intervals.size(), start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < length; i++)
        {
            if (intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);

                if (i == length - 1)
                {
                    ans.push_back({start, end});
                }
            }
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];

                if (i == length - 1)
                {
                    ans.push_back({start, end});
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    Solution sol;
    vector<vector<int>> ans = sol.merge(intervals);


    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}