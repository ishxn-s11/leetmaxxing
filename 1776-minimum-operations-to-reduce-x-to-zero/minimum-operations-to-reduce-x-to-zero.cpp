/*
Prefix Sum + Hashmap 

Let The Sum From Left Chosen Segment Of The Array And Right Chosen Segment 
Of The Array Be left And right Respectively, Also, Let The Total Sum Of 
The Array Be sum

According To The Problem, We Have To Choose Minimum Elements Of Right And Left
Such That left + right == x

This Is Equivalent To Maximizing A Window Of (sum-x)

Therefore, The Problem Becomes Identical To 'Maximum Subarray Sum Equals k'

Time Complexity: O(n)
Space Complexity: O(k) Where k Is The Size Of Map
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        unordered_map<int,int>mp;

        mp[0]=-1;

        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i;
        }

        if(sum<x) return -1;

        int rem=sum-x;
        int len=INT_MIN;

        sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            int s=sum-rem;

            if(mp.find(s)!=mp.end()){
                int idx=mp[s];

                len=max(len,i-idx);
            }
        }

        return len==INT_MIN?-1:(n-len);
    }
};