/*
https://leetcode.com/problems/4sum/

Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include <future>
#include <iostream>
#include <thread>

void compute(std::promise<int> p) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  p.set_value(42);
}

int main() {
  std::promise<int> p;
  std::future<int> f = p.get_future();

  std::thread t(compute, std::move(p));

  std::cout << "Waiting..." << std::endl;
  int result = f.get(); // blocks until promise sets a value

  std::cout << "Result = " << result << std::endl;

  t.join();
}
