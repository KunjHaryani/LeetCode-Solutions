// LeetCode 560 - Subarray Sum Equals K
// Link - https://leetcode.com/problems/subarray-sum-equals-k/
// Topic - Hash Table 
// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<long long, int>mp;
      int cnt=0;
      int n = nums.size();
      long long sum=0;
      mp[0]=1;

      for(int x: nums){
        sum+=x;
        long long rem = sum-k;
        if(mp.count(rem)) cnt+=mp[rem];
        mp[sum]++;
      }
      return cnt;
    }
};