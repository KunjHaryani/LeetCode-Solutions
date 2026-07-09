// LeetCode 1539 - Kth Missing Positve Number
// Link - https://leetcode.com/problems/kth-missing-positive-number/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return st + k;
    }
};