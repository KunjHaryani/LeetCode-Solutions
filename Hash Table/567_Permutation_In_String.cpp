// LeetCode 567 - Permutation In String
// Link - https://leetcode.com/problems/permutation-in-string/
// Topic - Hash Table 
// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:

    bool isfreqsame(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};

        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        int windSize=s1.length();
        for(int i=0;i<s2.length();i++){
            int windidx=0;
            int idx=i;
            int freqWind[26]={0};

            while(windidx<s1.length() && idx<s2.length()){
                freqWind[s2[idx]-'a']++;
                windidx++;
                idx++;
            }

            if(isfreqsame(freq,freqWind)){
                return true;
            }
        }
        return false;
    }
};