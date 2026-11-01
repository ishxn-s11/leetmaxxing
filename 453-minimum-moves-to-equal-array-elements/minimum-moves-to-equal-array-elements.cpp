/*
Optimal Approach 

Instead Of Simulated Operations:
ans=sum-(n*min)

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum=0;
        int mn=INT_MAX;

        for(int i:nums){
            sum+=i;
            mn=min(mn,i);
        }

        return sum-(long long)nums.size()*mn;
    }
};