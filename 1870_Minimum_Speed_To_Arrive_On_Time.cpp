// LeetCode 1870 - Minimum Speed To Arrive On Time
// Link - https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
// Topic - Binary Search 
// Time Complexity - O(log n)
// Space Complexity - O(1)
class Solution {
public:

    bool isvalid(vector<int>& dist, double hour,int mid){
        int n=dist.size();
        double x=0;
        for(int i=0;i<n-1;i++){
            x+=ceil((double)dist[i]/mid);
        }
        x+=(double)dist[n-1]/mid;
        if(x<=hour){
            return true;
        }
        else return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int M=INT_MIN;
        for(int i=0;i<n;i++){
            M=max(M,dist[i]);
        }
        int st=1;
        int end=M*1000;
        int ans=-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(isvalid(dist,hour,mid)){
                end=mid-1;
                ans=mid;
            }
            else st=mid+1;
        }
        return ans;
    }
};