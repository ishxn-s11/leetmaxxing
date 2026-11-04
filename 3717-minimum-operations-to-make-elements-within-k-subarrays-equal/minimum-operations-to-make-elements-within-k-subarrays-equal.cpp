/*
Optimal Approach

Create Two Multisets:left And right.
Maintain Their Sums: suml And sumr.
Insert The First x Elements Into The Multisets.
Rebalance Them So That:
- left Contains The Smaller Half.
- right Contains The Larger Half.
- left.size()==right.size() or left.size()==right.size()+1.
Find The Median Using The Largest Element Of Left.
Calculate the window cost:
cost=median*abs(left)-suml+sumr-median*abs(right)
Store The Cost in cost[]
For Every Subsequent Window:
1.Remove The Element Leaving The Window.
2.Update The Corresponding Multiset Sum.
3.Insert The New Incoming Element.
4.Rebalance Both Multisets.
5.Calculate And Store The New Window Cost.
Continue Until All Windows Of Length x Have Been Processed

Time Complexity: O(n*log(x)+n*k)
Space Complexity: O(n*k)
*/

typedef long long ll;
using mat=vector<vector<ll>>;

class Solution {
public:
    multiset<ll>left,right;
    ll suml=0,sumr=0;

    void rebalance(){

        while(left.size()>right.size()+1){
            ll x=*left.rbegin();
            left.erase(prev(left.end()));
            suml-=x;
            right.insert(x);
            sumr+=x;
        }

        while(left.size()<right.size()){
            ll x=*right.begin();
            right.erase(right.begin());
            sumr-=x;
            left.insert(x);
            suml+=x;
        }
    }

    void add(ll x){

        if(left.empty() || x<=*left.rbegin()){
            left.insert(x);
            suml+=x;
        }else{
            right.insert(x);
            sumr+=x;
        }

        rebalance();
    }

    void remove(ll x){
        auto it=left.find(x);

        if(it!=left.end()){
            left.erase(it);
            suml-=x;
        }else{
            it=right.find(x);
            right.erase(it);
            sumr-=x;
        }

        rebalance();
    }

    ll get_cost(){
        ll med=*left.rbegin();

        return med*left.size()-suml+sumr-med*right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        vector<ll>cost(n-x+1);
        left.clear();
        right.clear();
        suml=sumr=0;

        for(int i=0;i<n;i++){
            add(nums[i]);

            if(i>=x) remove(nums[i-x]);

            if(i>=x-1) cost[i-x+1]=get_cost();
        }

        const ll INF=LLONG_MAX/4;
        mat dp(n+1,vector<ll>(k+1,INF));

        for(int i=0;i<=n;i++) dp[i][0]=0;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j];

                if(i>=x && dp[i-x][j-1]!=INF)dp[i][j]=min(dp[i][j],dp[i-x][j-1]+cost[i-x]);
            }
        }

        return dp[n][k];
    }
};
