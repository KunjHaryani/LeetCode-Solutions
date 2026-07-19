// LeetCode 90 - Subsets II
// Link - https://leetcode.com/problems/subsets-ii/
// Topic - Backtracking
// Time Complexity - O(n * 2^n)
// Space Complexity - O(n * 2^n)
class Solution {
public:

    void getallsubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allsubsets){
        if(i==nums.size()){
            allsubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getallsubsets(nums,ans,i+1,allsubsets);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;

        //Exclude
        getallsubsets(nums,ans,idx,allsubsets);
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};