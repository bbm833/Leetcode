/*

https://leetcode.com/problems/search-a-2d-matrix/description/

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        int start = 0;
        int end = (n * m) -1;
        int mid;

        int mid_column;
        int mid_row;
        while(start <= end)
        {
            mid = (start+end) / 2;
            mid_row = mid / m;
            mid_column = mid % m;

            if(matrix[mid_row][mid_column] == target)
            {
                return true;
            }

            if(matrix[mid_row][mid_column] > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }

        }
        
        return false;
    }
};
