/*
Better Approach 

Generating Every Possible Subarray
Check Sum Of Every Subarray

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            int sum=0;

            for(int j=i;j<n;j++){
                sum+=nums[j];

                if(sum==k) cnt++;
            }
        }

        return cnt;
    }
};