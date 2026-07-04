// LeetCode 162 - Find Peak Element
// Link - https://leetcode.com/problems/find-peak-element/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        else if(nums[0]>nums[1]) return 0;
        else if(nums[n-1]>nums[n-2]) return n-1;
        int st=1;
        int end=n-2;
        while(st<=end){
            int mid = st +(end-st)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                st=mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                end=mid-1;
            }
            else st=mid+1;
        }
        return 0;
    }
};