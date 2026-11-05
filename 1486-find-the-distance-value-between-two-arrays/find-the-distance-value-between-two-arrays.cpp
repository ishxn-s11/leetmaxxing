/*
Optimal Approach

Sort arr2
Traverse arr1
Binary Search For Element >=x-d
If That Element Exists And Is Atmost x+d=> Reject x
Else Increment ans

Time Complexity: O(m*log(m)+n*log(m))
Space Complexity: O(1)
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;

        for(int i:arr1){
            auto it=lower_bound(arr2.begin(),arr2.end(),i-d);

            if(it==arr2.end() || *it>i+d) ans++;
        }

        return ans;
    }
};