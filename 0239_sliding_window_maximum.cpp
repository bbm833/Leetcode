/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> max_list{};
        std::vector<int> results{};

        for(std::size_t i=0U; i<nums.size(); ++i)
        {
            while(!max_list.empty() && nums[max_list.back()] < nums[i])
            {
                max_list.pop_back();
            }
                
            max_list.push_back(i);
            
            if (k <= i+1)
            {
                results.push_back(nums[max_list.front()]);
                while(!max_list.empty() && max_list.front() <= i+ 1- k)
                {
                    max_list.pop_front();
                }
            }
        }

        return results;
    }
};
