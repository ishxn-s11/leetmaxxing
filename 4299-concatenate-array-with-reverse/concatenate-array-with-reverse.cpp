class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(nums);
        reverse(nums.begin(),nums.end());

        for(int i:nums) res.push_back(i);

        return res;
    }
};