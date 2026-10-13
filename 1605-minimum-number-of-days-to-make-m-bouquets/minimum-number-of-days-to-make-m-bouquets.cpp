/*Binary Search*/

class Solution {
public:

    bool possible(vector<int>& bloomDay,int mid,int m,int k){
        int cnt=0,bq=0;
        int n=bloomDay.size();

        for(int i=0;i<n;i++){

            if(bloomDay[i]<=mid) cnt++;
            else{
                bq+=(cnt/k);
                cnt=0;
            }
        }

        bq+=(cnt/k);

        return bq>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        long long val=m*1LL*k*1LL;

        if(val>bloomDay.size()) return -1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }

        return ans;
    }
};