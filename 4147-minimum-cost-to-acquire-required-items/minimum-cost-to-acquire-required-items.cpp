/*
Optimal Approach

Greedily Select Items For Each Type

ans=min((need1*cost1+need2*cost2), => Buy Individual Items
       (k*costBoth+(need1-k)*cost1+(need2-k)*cost2), => Buy Combined Items While Both Requirements Remain
       (max(need1,need2)*costBoth) => Buy Combined Items For The Entire Larger Requirement

Time Complexity: O(min(need1,need2))
Space Complexity: O(1)
*/

typedef long long ll;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        ll opt1=1LL*need1*cost1+1LL*need2*cost2;
        ll k=min(need1,need2);
        ll opt2=k*costBoth+1LL*(need1-k)*cost1+1LL*(need2-k)*cost2;
        ll opt3=1LL*max(need1,need2)*costBoth;

        return min({opt1,opt2,opt3});
    }
};