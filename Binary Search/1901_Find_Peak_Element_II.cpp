// LeetCode 1901 - Find Peak Element II
// Link - https://leetcode.com/problems/find-a-peak-element-ii/
// Topic - Binary Search 
// Time Complexity - O(nlog m)
// Space Complexity - O(1)
class Solution {
public:
    int maxrow(vector<vector<int>>& mat, int mid, int m) {
        int max = INT_MIN;
        int row;
        for (int i = 0; i < m; i++) {
            if (max < mat[i][mid]) {
                max = mat[i][mid];
                row = i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int row = maxrow(mat, mid, m);
            int left,right;
            if (mid - 1 >= 0) {
                 left = mat[row][mid - 1];
            } else{
                 left = INT_MIN;}
            if (mid + 1 < n) {
                 right = mat[row][mid + 1];
            } else{
                 right = INT_MIN;}
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < mat[row][mid - 1])
                end = mid - 1;
            else if (mat[row][mid] < mat[row][mid + 1])
                st = mid + 1;
        }
        return {-1, -1};
    }
};