/*
Initialise depth=0,max_d=0
Traverse Every Character In s
If s[i]=='('{
    depth++
    Update max_d
}
If s[i]==')' => depth--
Return max_d

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDepth(string s) {
        int depth=0,max_d=0;

        for(char i:s){
            if(i=='('){
                depth++;
                max_d=max(max_d,depth);
            }else if(i==')') depth--;
        }

        return max_d;
    }
};