/*
Binary Search On The Possible Answers
*/

class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        int ans=1;

        if(x==0) return x;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(mid<=x/mid){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }

        return ans;
    }
};