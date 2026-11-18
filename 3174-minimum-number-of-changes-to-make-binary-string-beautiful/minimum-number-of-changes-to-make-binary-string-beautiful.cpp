/*
Brute Force 

Traverse The String For 2 Characters At A Time
Check If For Equaltiy => No Changes
Else => Increment ans

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minChanges(string s) {
        int changes=0;

        for(int i=0;i<s.size();i+=2){

            if(s[i]!=s[i+1]) changes++;
        }

        return changes;
    }
};