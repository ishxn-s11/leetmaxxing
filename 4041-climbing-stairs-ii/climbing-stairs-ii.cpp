/*
Optimal Approach-1 

Store Previously Calculated Results To Avoid Repeated Recursive Calls.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:

    int solve(int x,vector<int>& costs,vector<int>& dp){

        if(x==0) return 0;

        if(dp[x]!=-1) return dp[x];

        int ans=INT_MAX;

        for(int i=1;i<=3;i++){

            if(x-i>=0){
                int curr=solve(x-i,costs,dp)+costs[x-1]+i*i;
                ans=min(ans,curr);
            }
        }

        return dp[x]=ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);

        return solve(n,costs,dp);
    }
};