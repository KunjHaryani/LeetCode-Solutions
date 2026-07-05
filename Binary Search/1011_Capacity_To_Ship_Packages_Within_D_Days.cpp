// LeetCode 1011 - Capacity To Ship Packages Within D Days
// Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    bool isvalid(vector<int>& weights, int days, int n, int mid) {
        int x = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (weights[i] > mid)
                return false;
            sum += weights[i];
            if (sum > mid) {
                sum = 0;
                x++;
                i--;
            }
        }
        return (x <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
        }
        int st = 1;
        int end = sum;
        int ans;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isvalid(weights, days, n, mid)) {
                end = mid - 1;
                ans = mid;
            } else
                st = mid + 1;
        }
        return ans;
    }
};