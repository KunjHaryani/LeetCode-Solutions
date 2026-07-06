// LeetCode 1283 - Find The Smallest Divisor Given A Threshold
// Link - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    bool isvalid(vector<int>& nums, int threshold, int n, int mid) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] + mid - 1) / mid;
        }
        return (sum <= threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int m = INT_MIN;
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
        }
        int st = 1;
        int end = m;
        int ans;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isvalid(nums, threshold, n, mid)) {
                end = mid - 1;
                ans = mid;
            } else
                st = mid + 1;
        }
        return ans;
    }
};