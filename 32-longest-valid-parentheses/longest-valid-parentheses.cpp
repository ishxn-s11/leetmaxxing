//Optimal Approach-2
/*
Initalise Counters l and r as 0
Traverse The String
On Encountering '(' : l++ and ')' : r++
If l==r : Calculate Length
Else If : r>l ( Case Of ')') => l=r=0
Set l=r=0
Again Traverse From Back
On Encountering '(' : l++ and ')' : r++
If l==r : Calculate Length
Else If : l>r ( Case Of '(') => l=r=0

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int l=0,r=0;
        
        for(char i:s){
            if(i=='(') l++;
            else r++;
            if(l==r) ans=max(ans,2*r);
            else if(r>l) l=r=0;
        }

        l=r=0;

        for(int i=s.size()-1;i>=0;i--){

            if(s[i]=='(') l++;
            else r++;

            if(l==r) ans=max(ans,2*l);
            else if(l>r) l=r=0;
        }

        return ans;
    }
};
