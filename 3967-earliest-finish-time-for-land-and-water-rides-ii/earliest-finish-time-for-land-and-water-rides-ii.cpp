/*
Greedy Approach

Find Earliest Possible Time To Finish All Land Rides In Water Order
Find Earliest Possible Time To Finish All Water Rides In Land Order
Return Minimum Of The Two

Time Complexity: O(n*m)

*/

class Solution {

    static inline int MAX=300005;

public:
    int earliestFinishTime(vector<int>& la, vector<int>& lb, vector<int>& wa, vector<int>& wb) {
        int l=MAX,w=MAX,min_l=MAX,min_w=MAX;
        int n=la.size(),m=wa.size();

        for(int i=0;i<n;i++) l=min(l,la[i]+lb[i]);

        for(int i=0;i<m;i++){
            w=min(w,wa[i]+wb[i]);
            min_l=min(min_l,max(wa[i],l)+wb[i]);
        }

        for(int i=0;i<n;i++) min_w=min(min_w,max(la[i],w)+lb[i]);

        return min(min_w,min_l);
    }
};