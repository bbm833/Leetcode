/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_target{nums[0] + nums[1] + nums[2]};
        const int n = nums.size();

        std::sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i)
        {
            int start = i+1;
            int end = n-1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target)
                    return target;

                if(abs(target-sum) < abs(target-min_target))
                {
                    min_target = sum;
                }

                if(sum > target)
                {
                    --end;
                }
                else
                {
                    ++start;
                }                
            }
        }

        return min_target;
    }
};
