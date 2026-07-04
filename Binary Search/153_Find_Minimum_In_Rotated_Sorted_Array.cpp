// LeetCode 153 - Find Minimum In Rotated Sorted Array
// Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
       int n=nums.size();
       int st=0;
       int end=n-1;
       int ans=INT_MAX;
       while(st<=end){
        int mid=st + (end-st)/2;
            if(nums[mid]>=nums[st]){
                if(ans>nums[st]) ans=nums[st];
                st=mid+1;
            }
            else if(nums[end]>nums[mid]){
                if(ans>nums[end]) ans=nums[mid];
                end=mid-1;
            }
        }
        return ans;
       } 
    };