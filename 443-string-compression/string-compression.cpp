/*
Optimal Approach

Maintain Two Pointers
For Every Group{
    Store Current Character
    Count Consecutive Occurences
    Write The Character
    If freq>1 => Convert Count To Digit
}

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int str=0;
        int i=0;

        while(i<n){
            char curr=chars[i];
            int cnt=0;

            while(i<n && chars[i]==curr){
                cnt++;
                i++;
            }

            chars[str++]=curr;

            if(cnt>1){
                string s=to_string(cnt);

                for(char c:s) chars[str++]=c;
            }
        }
        
        return str;
    }
};