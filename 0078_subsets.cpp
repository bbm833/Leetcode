/*
https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results{};

        vector<int> current{};
        subsets_recursive(nums, 0, current, results);

        return results;
    }

    void subsets_recursive(const vector<int>& nums, int depth, vector<int>& current_set, vector<vector<int>>& results)
    {
        results.emplace_back(current_set);

        for(int i=depth; i<nums.size(); ++i)
        {
            current_set.emplace_back(nums[i]);
            subsets_recursive(nums, i+1, current_set, results);
            current_set.pop_back();
        }

    }
};
