class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i:nums) mp[i]++;

        int cnt=0;

        for(int i=0;i<n;i++){

            if(mp[nums[i]]<=0) continue;

            mp[nums[i]]--;
            int part=k-nums[i];

            if(mp[part]<=0){
                mp[nums[i]]++;
                continue;
            }

            mp[part]--;
            cnt++;
        }

        return cnt;
    }
};