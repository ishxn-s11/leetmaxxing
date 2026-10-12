/*
Binary Search

Time Complexity: O(n*log(max(piles)))
*/

class Solution {
public:
    long long f(vector<int>& piles,int mid){
        int n=piles.size();
        long long total=0;

        for(int i:piles) total+=(i+mid-1)/mid;

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=INT_MIN;

        while(low<=high){
            int mid=(low+high)/2;
            long long total=f(piles,mid);

            if(total<=h){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }

        return ans;
    }
};