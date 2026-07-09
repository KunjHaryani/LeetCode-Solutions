// LeetCode 240 - Search In A 2D Matrix II
// Link - https://leetcode.com/problems/search-a-2d-matrix-ii/
// Topic - Binary Search , Matrix
// Time Complexity - O(N+M)
// Space Complexity - O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m=matrix.size();
       int n=matrix[0].size();
       int r=0;
       int c=n-1;
       while(c>=0 && r<m){
        int mid=r+(c-r)/2;
        if(target==matrix[r][c]){
            return true;
        }
        else if(target<matrix[r][c]){
            c--;
        }
        else if(target>matrix[r][c]){
            r++;
        }
       }
       return false;
    }
};