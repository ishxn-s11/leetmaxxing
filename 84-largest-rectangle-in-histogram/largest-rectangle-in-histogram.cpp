class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        stk.push(-1);
        int max_ar=0;

        for(int i=0;i<heights.size();i++){

            while(stk.top()!=-1 && heights[i]<=heights[stk.top()]){
                int h=heights[stk.top()];
                stk.pop();
                int w=i-stk.top()-1;
                max_ar=max(max_ar,h*w);
            }

            stk.push(i);
        }

        while(stk.top()!=-1){
            int h=heights[stk.top()];
            stk.pop();
            int w=heights.size()-stk.top()-1;
            max_ar=max(max_ar,h*w);
        }

        return max_ar;        
    }
};