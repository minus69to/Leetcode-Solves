#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> tempAns;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    tempAns.insert(temp);

                    j++;
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
            }
        }

        vector<vector<int>> finalAns(tempAns.begin(), tempAns.end());
        return finalAns;
    }
};

int main()
{
    vector<int> nums = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};

    Solution sol;
    vector<vector<int>> finalAns = sol.threeSum(nums);

    for (auto x : finalAns)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}