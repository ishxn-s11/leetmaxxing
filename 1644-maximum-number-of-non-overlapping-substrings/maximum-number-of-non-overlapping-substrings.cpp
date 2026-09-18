/*
Greedy Interval Scheduling

Time Complexity: O(n*k+k*log(k)) where k=26 
*/
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>first(26,-1),last(26,-1);
        int n=s.size();

        for(int i=0;i<n;i++) last[s[i]-'a']=i;
        for(int i=n-1;i>=0;i--) first[s[i]-'a']=i;

        vector<pair<int,int>>intvl;

        for(int i=0;i<n;i++){

            if(i==first[s[i]-'a']){
                int r=last[s[i]-'a'],j=i;
                bool valid=true;

                while(j<=r){
                    if(first[s[j]-'a']<i){
                        valid=false;
                        break;
                    }

                    r=max(r,last[s[j]-'a']);
                    j++;
                }

                if(valid) intvl.push_back({r,i});
            }
        }

        sort(intvl.begin(),intvl.end());

        vector<string>ans;
        int end=-1;

        for(auto& i:intvl){
            int r=i.first;
            int l=i.second;

            if(l>end){
                ans.push_back(s.substr(l,r-l+1));
                end=r;
            }
        }

        return ans;
    }
};