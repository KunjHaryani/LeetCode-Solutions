// LeetCode 81 - Search In Rotated Sorted Array II
// Link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n=nums.size();
       int st=0;
       int end=n-1;
       while(st<=end){
        int mid = st + (end-st)/2;
        if(nums[mid]==target){
            return true;
        }
        if(nums[st]==nums[mid] && nums[mid]==nums[end]){
            st++;
            end--;
        }
        else if(nums[st]<=nums[mid]){
            if(nums[st]<= target && target<=nums[mid]){
                end=mid-1;
            }
            else st=mid+1;
        }
        else{
            if(nums[mid] <= target && target <=nums[end]){
                st=mid+1;
            }
            else end=mid-1;
        }
       }
       return false; 
    }
};