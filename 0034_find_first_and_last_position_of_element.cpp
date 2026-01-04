/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {

    int left = 0;
    int right = nums.size() - 1;
    int mid{};
    int start{-1};
    int end{-1};

    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) {
        start = mid;
        right = mid - 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) {
        end = mid;
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    if (start != -1 && end != -1) {
      return vector<int>{start, end};
    }
    return vector<int>{-1, -1};
  }
};
