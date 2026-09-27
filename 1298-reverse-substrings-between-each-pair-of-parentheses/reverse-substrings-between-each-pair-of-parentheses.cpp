/*
Optimal Approach Wormhole Traversal

Instead Of Physically Reversing Substrings,
Simulate Reversal By Changing Our Traversal Direction.

Mantain A Stack Of Indicess For Finding Matching Parenthesis
Store The Indices In A Vector
Traverse
When A Parenthesis Is Encountered{
    Jump To Its Matching Parenthesis
    Reverse The Direction
}
When A Letter Is Encountered => Append To The ans

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int>vec(n);
        stack<int>stk;

        for(int i=0;i<n;i++){
            if(s[i]=='(') stk.push(i);
            else if(s[i]==')'){
                int j=stk.top();
                stk.pop();

                vec[i]=j;
                vec[j]=i;
            }
        }

        string ans;
        int dir=1;

        for(int i=0;i<n;i+=dir){
            if(s[i]=='(' || s[i]==')'){
                i=vec[i];
                dir=-dir;
            }else ans+=s[i];
        }

        return ans;
    }
};