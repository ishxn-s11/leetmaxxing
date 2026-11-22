//Two Pointer Approach

class Solution {
public:
    int maxArea(vector<int>& height){
        int ans=0;
        int l=0,r=height.size()-1;

        while(l<r){
            int w=r-l;
            int h=min(height[l],height[r]);
            int water=w*h;
            ans=max(ans,water);
            height[l]<height[r]?l++:r--;
        }

        return ans;
    }
};