class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;

        for(auto& list:knowledge) mp[list[0]]=list[1];

        string key="";
        string res="";
        bool flag=false;

        for(char i:s){
            if(i=='(') flag=true;
            else if(i==')'){
                if(mp.find(key)!=mp.end()) res+=mp[key];
                else res+="?";

                flag=false;
                key="";
            }
            else if(flag) key+=i;
            else res+=i;
        }

        return res;
    }
};