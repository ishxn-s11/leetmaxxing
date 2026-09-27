/*
Brute Force

Maintain A Stack
Traverse 
If The Character Is A Letter Or '(' => Push
If The Character Is ')' => Pop Until '(' Is Encountered
Remove '(' And Push The Popped Characters Back In The Same Order Back Into The Stack.

Time Complexity: O(n^2)
Space Complexity: O(n)

*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>stk;

        for(char i:s){
            if(i!=')') stk.push(i);
            else{
                string temp;

                while(stk.top()!='('){
                    temp+=stk.top();
                    stk.pop();
                }

                stk.pop();

                for(char j:temp) stk.push(j);
            }
        }

        string ans;

        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};