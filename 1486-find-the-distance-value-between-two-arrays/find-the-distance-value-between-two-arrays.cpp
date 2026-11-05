/*
Brute Force

For Each Element x in arr1{
    Traverse Every Element In arr2{
        Calculate dist=abs(x-y)
        If dist<=d=>Mark x As Invalid
        If No Such y Exists,Increment ans
    }
}

Time Complexity: O(n*m)
Space Complexity: O(1)
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;

        for(int i:arr1){

            bool valid=true;

            for(int j:arr2){
                
                if(abs(i-j)<=d){
                    valid=false;
                    break;
                }
            }
            
            if(valid) ans++;
        }

        return ans;
    }
};