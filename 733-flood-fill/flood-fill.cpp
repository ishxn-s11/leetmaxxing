/*
Brute Force 

DFS
*/
using mat=vector<vector<int>>;
class Solution {
public:
    void DFS(mat& img,int i,int j,int old,int clr){
        int n=img.size();
        int m=img[0].size();

        if(i<0 || i>=n || j<0 || j>=m) return;

        if(img[i][j]!=old) return;

        img[i][j]=clr;

        DFS(img,i+1,j,old,clr);
        DFS(img,i-1,j,old,clr);
        DFS(img,i,j+1,old,clr);
        DFS(img,i,j-1,old,clr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];

        if(old==color) return image;

        DFS(image,sr,sc,old,color);

        return image;
    }
};