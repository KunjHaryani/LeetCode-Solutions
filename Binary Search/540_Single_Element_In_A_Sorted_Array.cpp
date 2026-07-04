// LeetCode 540 - Single Element In A Sorted Array 
// Link - https://leetcode.com/problems/single-element-in-a-sorted-array/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        if(n==1) return nums[0];
        while(st<=end){
            int mid = st + (end-st)/2;
            if(mid==0 && nums[mid]!=nums[1]) return nums[mid];
            if(mid==n-1 && nums[mid]!=nums[n-2]) return nums[mid];

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            else if(mid % 2 !=0){

                if(nums[mid-1]==nums[mid]) // Right Side Search
                    st=mid+1;
                
                else if(nums[mid]==nums[mid+1]) // Left Side Search
                    end=mid-1;
            }

            else if(mid % 2 == 0){

                if(nums[mid-1]==nums[mid]) // Left Side Search
                    end=mid-1;

                else if(nums[mid]==nums[mid+1]) // Right Side Search
                    st=mid+1;
            }
        }
        return 0;
    }
};