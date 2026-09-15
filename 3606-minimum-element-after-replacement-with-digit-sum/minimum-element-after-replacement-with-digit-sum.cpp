class Solution {
public:
    int sum(int x){
        int s=0;

        while(x>0){
            s+=x%10;
            x/=10;
        }

        return s;
    }

    int minElement(vector<int>& nums) {
        int m=INT_MAX;

        for(int i:nums) m=min(m,sum(i));

        return m;
    }
};