// LeetCode 35 - Search Insert Position
// Link - https://leetcode.com/problems/search-insert-position/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int k;
        
        if(target>nums[n-1]) return n;
        while(st<=end){
            int mid=st + (end-st)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
                k=mid;
            }
            else{
                st=mid+1;
            }
        }
        return k;
    }
};