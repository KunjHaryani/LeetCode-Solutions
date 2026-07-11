// LeetCode 1 - Two Sum
// Link - https://leetcode.com/problems/two-sum/
// Topic - Hash Table 
// Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            int first = nums[i];
            int sec = target - first;
            if (m.find(sec) != m.end()) {
                return {i, m[sec]};
            } else {
                m[first] = i;
            }
        }
        return {};
    }
};