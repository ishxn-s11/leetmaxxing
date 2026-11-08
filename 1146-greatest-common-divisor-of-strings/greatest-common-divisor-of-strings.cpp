/*
Brute Force 

Iterate From Shorter String Decrementing To 1
Skip Lengths That Don't Divide Both String Lengths
Take Substring Of That Length
Check If Repeating This Substring Gets Both String

Time Complexity: O(min(n,m)*(n+m))
Space Complexity: O(min(n,m))
*/

class Solution {
public:
    bool check(string s,string x){

        for(int i=0;i<s.size();i++){

            if(s[i]!=x[i%x.size()]) return false;
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        for(int i=min(n,m);i>=1;i--){

            if(n%i!=0 || m%i!=0) continue;

            string x=str1.substr(0,i);

            if(check(str1,x) && check(str2,x)) return x;
        }

        return "";
    }
};