#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int length = nums.size();
        int currentSum = 0, maxSum = INT_MIN;

        for (int i = 0; i < length; i++)
        {
            currentSum += nums[i];

            maxSum = max(maxSum, currentSum);

            currentSum < 0 ? currentSum = 0 : currentSum = currentSum;
        }

        return maxSum;
    }
};

int main()
{
    vector<int> nums = {5, 4, -1, 7, 8};
    Solution sol;

    cout << sol.maxSubArray(nums);

    return 0;
}