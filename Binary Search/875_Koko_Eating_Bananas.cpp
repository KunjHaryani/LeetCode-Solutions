// LeetCode 875 - Koko Eating Bananas
// Link - https://leetcode.com/problems/koko-eating-bananas/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    bool isvalid(vector<int>& nums, int h, int n, int mid) {
        long long x = 0;
        for (int i = 0; i < n; i++) {
            x += (nums[i] + mid - 1) / mid;
        }
        return (x <= h);
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        int m = INT_MIN;
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
        }
        int st = 1;
        int end = m;
        int k;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isvalid(nums, h, n, mid)) {
                k = mid;
                end = mid - 1;
            } else
                st = mid + 1;
        }
        return k;
    }
};