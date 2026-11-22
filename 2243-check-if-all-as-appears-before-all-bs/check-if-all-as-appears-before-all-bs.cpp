/*
Maintain seenb=false
Traverse 
If curr='b', Set seenb=true 
If curr='a', Set seenb=true And Return False
Return True

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkString(string s) {
        bool seen=false;

        for(char i:s){

            if(i=='b') seen=true;
            else if(i=='a' && seen) return false;
        }

        return true;
    }
};