/*

https://leetcode.com/problems/contains-duplicate-ii/description/

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

Topics
	- Array
	- Hash Table
	- Sliding Window
*/

#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, std::size_t> index_map{};

        for(std::size_t i=0U; i < nums.size(); ++i)        
        {
            const auto& it = index_map.find(nums[i]);
            if(it != index_map.end())
            {
                if( i - it->second <= k)
                    return true;
            }
            index_map[nums[i]] = i;
        }

        return false;
    }

};
