class Solution {
public:
    //Optimal Approach
    
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0,len=0;
        int l=0,r=0,z=0;

        while(r<nums.size()){

            if(nums[r]==0) z++;

            while(z>k){

                if(nums[l]==0)z--;

                l++;
            }

            if(z<=k){
                len=r-l+1;
                maxlen=max(len,maxlen);
            }

            r++;
        }

        return maxlen;
    }
};