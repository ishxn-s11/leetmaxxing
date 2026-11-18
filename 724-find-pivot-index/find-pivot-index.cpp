class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0,lsum=0;
        int rsum=0;

        for(int i:nums) total+=i;

        for(int i=0;i<nums.size();i++){
            rsum=total-lsum-nums[i];

            if(lsum==rsum) return i;
            
            lsum+=nums[i];
        }

        return -1;
    }
};