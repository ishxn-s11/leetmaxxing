/*
Optimal Approach : Backtracking

Try->Explore->Undo

At Any Point:
We Can Add '(' If Number Of '(' Used < n
We Can Add ')' If '(' < ')'

For Transition We Need: 
Current String
Number Of Open Parenthenes
Number Of Closed Parenthe

Time Complexity: O(Cn) Where Cn Is Catalan Number
Space Complexity: O(n)
*/

class Solution {
public:
    void solve(int n,string curr,int open,int close,vector<string>&ans){
        if(curr.length()==2*n){
            ans.push_back(curr);

            return;
        }
        if(open<n) solve(n,curr+'(',open+1,close,ans);
        if(close<open) solve(n,curr+')',open,close+1,ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        solve(n,"",0,0,ans);

        return ans;
    }
};