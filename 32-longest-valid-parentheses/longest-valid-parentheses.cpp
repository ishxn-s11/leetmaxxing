//Optimal Approach-1
/*
Initalise A Stack With -1 On Top To Store Indices
Traverse The String
Push The Index When '('
Pop The Index When ')'
If Stack Is Empty, Store Current Index As Starting Point 
Else Calculate The Length : Current Index-Top Of The Stack
Update The Length

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        int ans=0;
        stk.push(-1);
        
        for(int i=0;i<s.size();i++){

            if(s[i]=='(') stk.push(i);
            else{
                stk.pop();

                if(stk.empty()) stk.push(i);
                else ans=max(ans,i-stk.top());
            }
        }

        return ans;
    }
};