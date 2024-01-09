#include <bits/stdc++.h>
using namespace std;

int positionStart(vector<int> &nums, int start)
{
    if (nums[start] != 0)
    {
        return start;
    }

    return positionStart(nums, start + 1);
}

int positionEnd(vector<int> &nums, int end)
{
    if (nums[end] != 0)
    {
        return end;
    }

    return positionStart(nums, end - 1);
}

void print(vector<int> &nums)
{
    int length = nums.size();

    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Solution sol;
    // vector<int> nums = {1, 2, 0};
    vector<int> nums = {2, 2, 1, 1, 0, 0};

    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    

    print(nums);

    return 0;
}