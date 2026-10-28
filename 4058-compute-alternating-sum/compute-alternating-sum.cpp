class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        bool on=true;
        int sum=0;

        for(int i:nums){
            
            if(on) sum+=i;
            else sum-=i;

            on=!on;
        }

        return sum;
    }
};