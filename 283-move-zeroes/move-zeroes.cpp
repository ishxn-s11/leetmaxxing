/*
Better Approach

Maintain z
Traverse nums
If nums[i]!=0{
    Swap With nums[z]
    Increment z
}
Repeat

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]!=0){
                swap(nums[i],nums[z]);
                z++;
            }
        }        
    }
};