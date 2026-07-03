// LeetCode 704 - Find First And Last Position Of Element In Sorted Array
// Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:
    int findfirst(vector<int> &nums,int target){
            int n=nums.size();
            int st=0;
            int end=n-1;
            int ans=-1;
            while(st<=end){
                int mid= st+(end-st)/2;
                if(nums[mid]==target){
                    ans=mid;
                    end=mid-1;
                }
                else if(nums[mid]<target){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            return ans;
        }

        int findlast(vector<int> &nums,int target){
            int n=nums.size();
            int st=0;
            int end=n-1;
            int ans=-1;
            while(st<=end){
                int mid= st+(end-st)/2;
                if(nums[mid]==target){
                    ans=mid;
                    st=mid+1;
                }
                else if(nums[mid]<target){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            return ans;
        }
        
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        ans[0]=findfirst(nums,target);
        ans[1]=findlast(nums,target);
        return ans;
    }
};