/*
Brute Force

Create A Temporary Array
Traverse And Store All Non-Zero Elements
Append 0s
Copy Back To The Original Array

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;

        for(int i=0;i<nums.size();i++){

            if(nums[i]!=0) temp.push_back(nums[i]);
        }

        while(temp.size()<nums.size()) temp.push_back(0);

        for(int i=0;i<nums.size();i++) nums[i]=temp[i];
    }
};