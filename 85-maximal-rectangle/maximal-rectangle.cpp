
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int n=matrix.size(),m=matrix[0].size();
        int max_ar=0;
        vector<vector<int>>pfx(n,vector<int>(m));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++) pfx[i][j]=matrix[i][j]-'0';
        }

        for(int i=0;i<n;i++){

            for(int j=1;j<m;j++){

                if(pfx[i][j]==1) pfx[i][j]+=pfx[i][j-1];
            }
        }

        for(int j=0;j<m;j++){

            for(int i=0;i<n;i++){

                int w=pfx[i][j];

                if(w==0) continue;

                int curr=w;

                for(int k=i;k<n && pfx[k][j]>0;k++){
                    curr=min(curr,pfx[k][j]);
                    int h=k-i+1;
                    max_ar=max(max_ar,curr*h);
                }

                curr=w;

                for(int k=i;k>=0 && pfx[k][j]>0;k--){
                    curr=min(curr,pfx[k][j]);
                    int h=i-k+1;
                    max_ar=max(max_ar,curr*h);
                }
            }
        }

        return max_ar;
    }
};
