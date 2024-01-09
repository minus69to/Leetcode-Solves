#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = 1;

        while (k <= m + n)
        {

            if (i >= 0 && j >= 0)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[m + n - k] = nums1[i];
                    i--;
                }
                else
                {
                    nums1[m + n - k] = nums2[j];
                    j--;
                }
            }
            else if (i >= 0)
            {
                nums1[m + n - k] = nums1[i];
                i--;
            }
            else if (j >= 0)
            {
                nums1[m + n - k] = nums2[j];
                j--;
            }

            k++;
        }
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    solution.merge(nums1, 3, nums2, 3);

    for (auto x : nums1)
    {
        cout << x << " ";
    }

    return 0;
}