/*
https://leetcode.com/problems/permutations/description/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results{};

        do
        {
            results.emplace_back(nums);
        }
        while (std::next_permutation(nums.begin(), nums.end()));
        //while (my_next_permutation(nums));
   
        return results;
    }

    bool my_next_permutation(vector<int>& nums)
    {
        // Find pivot
        const int n = nums.size();
        std::optional<int> pivot;
        for(int i=n-1; i>0; --i)
        {
            if(nums[i] > nums[i-1])
            {
                pivot = i-1;
                break;
            }
        }

        if(!pivot.has_value())
        {
            return false;
        }

        // find sucessor
        int successor = n - 1;
        while (nums[successor] <= nums[pivot.value()])
        {
            --successor;
        }

        // swap pivot and sucessor
        std::swap(nums[successor], nums[pivot.value()]);

        // reverse after pivot
        std::reverse(nums.begin()+pivot.value()+1, nums.end());

        return true;
    }
    
};
