#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<double> total;
        int len1 = nums1.size();
        int len2 = nums2.size();

        int l1 = 0, l2 = 0, lt = 0;

        while (l1 < len1 || l2 < len2)
        {
            if (l1 < len1 && l2 < len2)
            {
                if (nums1[l1] <= nums2[l2])
                {
                    total.push_back(nums1[l1]);
                    l1++;
                }
                else if (nums2[l2] < nums1[l1])
                {
                    total.push_back(nums2[l2]);
                    l2++;
                }
            }
            else if (l1 < len1)
            {
                total.push_back(nums1[l1]);
                l1++;
            }
            else if (l2 < len2)
            {
                total.push_back(nums2[l2]);
                l2++;
            }

            lt++;
        }

        if (lt % 2 == 0)
        {
            int mid = lt / 2;
            return (total[mid - 1] + total[mid]) / 2;
        }
        else
        {
            int mid = lt / 2;
            return total[mid];
        }
    }
};

int main()
{
    vector<double> nums1 = {1};
    vector<double> nums2 = {};
    vector<double> total;

    int len1 = nums1.size();
    int len2 = nums2.size();

    int l1 = 0, l2 = 0, lt = 0;

    while (l1 < len1 || l2 < len2)
    {
        if (l1 < len1 && l2 < len2)
        {
            if (nums1[l1] <= nums2[l2])
            {
                total.push_back(nums1[l1]);
                l1++;
            }
            else if (nums2[l2] < nums1[l1])
            {
                total.push_back(nums2[l2]);
                l2++;
            }
        }
        else if (l1 < len1)
        {
            total.push_back(nums1[l1]);
            l1++;
        }
        else if (l2 < len2)
        {
            total.push_back(nums2[l2]);
            l2++;
        }

        // if (nums1[l1] <= nums2[l2])
        // {
        //     total.push_back(nums1[l1]);
        //     l1++;
        // }
        // else if (nums2[l2] < nums1[l1])
        // {
        //     total.push_back(nums2[l2]);
        //     l2++;
        // }
        lt++;
    }

    if (lt % 2 == 0)
    {
        int mid = lt / 2;
        cout << (total[mid - 1] + total[mid]) / 2 << endl;
    }
    else
    {
        int mid = lt / 2;
        cout << total[mid] << endl;
    }

    // cout << lt << endl;
    // for (auto x : total)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    return 0;
}