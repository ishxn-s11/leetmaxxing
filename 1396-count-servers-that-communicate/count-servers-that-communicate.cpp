/*
Optimal Approach

Maintain Two Vectors For Row Count And Column Count
Precompute Occurence Of 1 With The Vectors
A Server Communicates If : rcnt[i]>1 || ccnt[j]>1

Time Complexity: O(m*n)
Space Complexity: O(m+n)
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>rcnt(n,0);
        vector<int>ccnt(m,0);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    rcnt[i]++;
                    ccnt[j]++;
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(grid[i][j]==1 && (rcnt[i]>1 || ccnt[j]>1)) ans++;
            }
        }

        return ans;
    }
};