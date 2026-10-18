/*
Brute Force 

Binary Search On Every Row 

Time Complexity: O(n*log(m))
Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();

        for(int i=0;i<n;i++){
            bool found=binary_search(matrix[i].begin(),matrix[i].end(),target);

            if(found) return true;
        }

        return false;
    }
};