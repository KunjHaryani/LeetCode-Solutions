// LeetCode 33 - Search In Rotated Sorted Array I
// Link - https://leetcode.com/problems/search-in-rotated-sorted-array/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
     while(st<=end){
        int mid=st + (end-st)/2 ;
        if(target==nums[mid]){
            return mid;
        }
        if(nums[st]<=nums[mid]){
            if(nums[st] <= target && nums[mid] >= target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        else{
            if(nums[mid] <= target && nums[end] >=target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }  
    return -1;
    }
};