/*
https://leetcode.com/problems/jump-game-ii/

You are given a 0-indexed array of integers nums of length n. You are initially
positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index
i. In other words, if you are at index i, you can jump to any index (i + j)
where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are
generated such that you can reach index n - 1.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
step from index 0 to 1, then 3 steps to the last index. Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/

class Solution {
public:
  /*int jump(vector<int>& nums) {
      std::queue<std::pair<int, int>> indexes{};
      indexes.push({0, 0});

      const int n = nums.size();
      std::vector<bool> visited(n, false);
      while(indexes.size() > 0)
      {
          auto [index, count] = indexes.front();
          indexes.pop();


          //std::cout << "popped index: " << index << " count: " << count << "
  step: " << nums[index] <<std::endl; for(int i=1; i<nums[index]+1; ++i)
          {

              if(index+i == n-1)
                  return count+1 ;
              if(index+i < n  && visited[index+i] == false)
              {
                  indexes.push({index+i, count+1});
                  visited[index+i] = true;
                  //std::cout << "pushed index: " << index+i << " count: " <<
  count+1 << std::endl;
              }
          }


      }

      return 0;
  }*/

  int jump(vector<int> &nums) {
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
      farthest = std::max(farthest, nums[i] + i);

      if (current_end == i) {
        ++jumps;
        current_end = farthest;
      }
    }

    return jumps;
  }
};
