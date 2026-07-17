// LeetCode 560 - Subarray Sum Equals K
// Link - https://leetcode.com/problems/subarray-sum-equals-k/
// Topic - Hash Table 
// Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(freq==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                freq++;
            }
            else freq--;
        }
    return ans;
    }
};