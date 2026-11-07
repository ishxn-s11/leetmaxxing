class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int n=min(word1.size(),word2.size());

        for(int i=0;i<n;i++){
            res+=word1[i];
            res+=word2[i];
        }
        
        res+=word1.substr(n);
        res+=word2.substr(n);

        return res;
    }
};