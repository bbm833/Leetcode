/*
https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });

    /*for(const auto& interval: intervals)
    {
        std::cout << interval[0] << " "  << interval[1] << std::endl;
    }*/

    const int n = intervals.size();
    vector<vector<int>> result{intervals[0]};
    for(int i=1; i<n; ++i)
    {
        if((result[result.size()-1][0] <= intervals[i][0] && result[result.size()-1][1] >= intervals[i][0]) || (result[result.size()-1][0] <= intervals[i][1] && result[result.size()-1][1] >= intervals[i][1]))
        {
            result[result.size()-1][0] = min(result[result.size()-1][0], intervals[i][0]);
            result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
        }
        else
        {
            vector<int> new_interval{intervals[i]};
            result.emplace_back(new_interval);
        }
    }
    return result;
    }
};
