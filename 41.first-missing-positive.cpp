/*
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (25.81%)
 * Total Accepted:    124.8K
 * Total Submissions: 483.6K
 * Testcase Example:  '[1,2,0]'
 *
 * 
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * 
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * 
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        auto l = nums.size();
        int i;
        for (i = 0; i < l; ++i)
        {
            if (nums[i] > 0 && nums[i] <= l && nums[i] != i + 1)
            {
                if (nums[i] == nums[nums[i] - 1]) continue;
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (i = 0; i < l; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return l + 1;
    }
};
