/*
Optimal Approach

Let The Element That Every Other Element Has To Be Equal
To Be x
For Each Element, We Need: abs(nums[i]-x)
Therefore, Total Moves=sum(abs(nums[i]-x))

To Minimize abs(nums[i]-x), We Need median
So, The Expression Becomes abs(nums[i]-median)

Sort The Array
Find The Median
Calculate Total Moves

Time Complexity: O(n*log(n))
Space Complexity: O(1)
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int med=nums[n/2];
        long long ans=0;

        for(int i:nums) ans+=abs((long long)i-med);

        return (int)ans;
    }
};