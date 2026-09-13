/*
Optimal Approach Bitmasking

Since The Matrix Is Binary, Each Of Its Row Can Be Considered A Number Is Binary Representation 
And If We Apply Horizontal Shift Using << Operator 
And Apply AND Operation , We Get The Numnber Of 1s Overlapping 

Time Complexity: O(n^3)
Space Complexity: O(n)

*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<int>r1(n,0);
        vector<int>r2(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (img1[i][j]==1) r1[i]|=(1<<j);
                if (img2[i][j]==1) r2[i]|=(1<<j);
            }
        }

        int ans=0;

        for(int rshift=-(n-1);rshift<=n-1;rshift++){
            for(int cshift=-(n-1);cshift<=n-1;cshift++) {
                int overlap=0;

                for(int i=0;i<n;i++){
                    int j=i+rshift;

                    if(j<0 || j>=n) continue;

                    int shift;

                    if(cshift>=0) shift=r1[i]<<cshift;
                    else shift=r1[i]>>(-cshift);

                    overlap+=__builtin_popcount(shift & r2[j]);
                }

                ans=max(ans,overlap);
            }
        }

        return ans;
    }
};