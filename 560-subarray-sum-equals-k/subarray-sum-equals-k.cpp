/*
Optimal Approach 

Initialise Hashmap
Store freq[0]=1
Initialise pfx=0,cnt=0
Traverse nums
Add Current Element pfx+=nums[i]
Calculate Needed Prefix need=pfx-k
If need Exists In Hashmap => cnt+=freq[need]
Store Current pfx As freq[pfx]++

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;

        freq[0]=1;

        int pfx=0,cnt=0;

        for(int i:nums){
            pfx+=i;
            int need=pfx-k;

            if(freq.find(need)!=freq.end()) cnt+=freq[need];

            freq[pfx]++;
        }

        return cnt;
    }
};