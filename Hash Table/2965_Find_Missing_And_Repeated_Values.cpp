// LeetCode 2965 - Find Missing And Repeated Values
// Link - https://leetcode.com/problems/find-missing-and-repeated-values/
// Topic - Hash Table 
// Time Complexity - O(n^2)
// Space Complexity - O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        int a, b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    break;
                }
                s.insert(grid[i][j]);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
        }
        int N = n * n;
        b = N * (N + 1) / 2 - sum + a;
        return {a, b};
    }
};