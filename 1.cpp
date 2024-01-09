#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> ans;
		unordered_multimap<int, int> umap;

		for (int i = 0; i < nums.size(); i++)
		{
			umap.insert({nums[i], i});
		}

		for (auto x : umap)
		{
			cout << x.first << " " << x.second << endl;
		}
		cout << endl;

		for (auto x : nums)
		{
			auto range1 = umap.equal_range(x);
			vector<int> values1;

			for (auto it = range1.first; it != range1.second; ++it)
			{
				values1.push_back(it->second);
			}

			if (values1.size() > 2)
			{
				continue;
			}
			else
			{
				ans.push_back(values1[values1.size() - 1]);
				values1.pop_back();
			}

			if (umap.find(target - x) != umap.end())
			{
				if (x == target - x)
				{
					if (values1.size() > 0)
					{
						ans.push_back(values1[values1.size() - 1]);
					}
					else
					{
						ans.clear();
						values1.clear();
						continue;
					}
				}
				else
				{
					auto range2 = umap.equal_range(target - x);
					vector<int> values2;

					for (auto it = range2.first; it != range2.second; ++it)
					{
						values2.push_back(it->second);
					}
					ans.push_back(values2[values2.size() - 1]);
				}
				break;
			}
			else
			{
				ans.clear();
				values1.clear();
			}
		}

		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = {0, 0};
	int target = 0;
	vector<int> ans = sol.twoSum(nums, target);

	for (auto x : ans)
	{
		cout << x << " ";
	}

	return 0;
}