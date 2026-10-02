/*
Calculate The Previous Greater Element For Each Element 
And, The Calculate The Difference Of Indices From Both 
Using A Stack

Time Complexity: O(2*n)
Space Complexity: O(n)
*/

class StockSpanner {
public:
    
    stack<pair<int,int>>stk;
    int idx=-1;

    StockSpanner(){
        idx=-1;
        while(!stk.empty()) stk.pop();
    }
    
    int next(int price) {
        idx++;
        while(!stk.empty() && stk.top().first<=price) stk.pop();

        int ans=idx-(stk.empty()?-1:stk.top().second);
        stk.push({price,idx});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */