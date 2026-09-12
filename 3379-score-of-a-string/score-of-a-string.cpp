class Solution {
public:
    int scoreOfString(string s) {
        int sum=0,diff;

        for(int i=1;i<s.size();i++){
            diff=abs((s[i]-'a')-(s[i-1]-'a'));
            sum+=diff;
        }

        return sum;
    }
};