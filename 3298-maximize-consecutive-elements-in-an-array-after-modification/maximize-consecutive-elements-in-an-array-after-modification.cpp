/*
Optimal Approach

Sort The Array 
Map Out dp[x]=Maxmium Length Of A Valid Subsequence With x 
Either Modify The Element (dp[i]=dp[i-1]+1)
Or Don't Modify (dp[i]=dp[i+1]-1)

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>dp;
        int ans=0;

        for(int i:nums){
            dp[i+1]=dp[i]+1;
            dp[i]=dp[i-1]+1;
            ans=max({ans,dp[i],dp[i+1]});
        }

        return ans;
    }
};