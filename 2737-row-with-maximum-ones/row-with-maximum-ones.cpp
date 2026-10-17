class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0,s=0;

        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            
            int id=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
            int x=m-id;

            if(x>s){
                s=x;
                ans=i;
            }
        }    

        return {ans,s};
    }
};