#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return;
    }

    swap(nums[start], nums[end]);
    reverse(nums, start + 1, end - 1);
}

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int length = nums.size();
        int start = 0, end = length - 1;

        for (int i = length - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                start = i - 1;
                end = i;
                break;
            }
        }

        if (start == 0 && end == length - 1)
        {
            reverse(nums, start, end);
        }
        else
        {
            sort(nums.begin() + start + 1, nums.end());
            for (int i = start; i < length - 1; i++)
            {
                if (nums[start] < nums[i + 1])
                {
                    swap(nums[start], nums[i + 1]);
                    break;
                }
            }
        }
    }
};

int main()
{
    vector<int> nums = {1, 3, 2};
    Solution sol;
    sol.nextPermutation(nums);


    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}