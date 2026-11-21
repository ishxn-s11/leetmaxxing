/*
Maintain The Most Recent Node For Each Character
If We Need The Closest Ancestor With A Character, We Can Immediately Get Its Parent

For Each Node{
    Store Previous Value Of last[s[u]]
    Set last[s[u]]=u
    Search Parent Of u Using Previous Ancestor In last 
    Process Children
    Restore The Old Value Of last[s[u]] When Returning.
}

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:

    void findpar(int u,vector<vector<int>>& tree,vector<int>& parent,string& s,vector<int>& last,vector<int>& newpar){
        int c=s[u]-'a';
        int prev=last[c];

        if(prev!=-1) newpar[u]=prev;
        else newpar[u]=parent[u];

        last[c]=u;

        for(int v:tree[u]) findpar(v,tree,parent,s,last,newpar);

        last[c]=prev;
    }

    int DFS(int u,vector<vector<int>>& tree,vector<int>& ans){
        int size=1;

        for(int v:tree[u]) size+=DFS(v,tree,ans);

        ans[u]=size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>tree(n);

        for(int i=1;i<n;i++) tree[parent[i]].push_back(i);

        vector<int>last(26,-1);
        vector<int>newpar(n);
        findpar(0,tree,parent,s,last,newpar);
        vector<vector<int>>modified(n);

        for(int i=1;i<n;i++) modified[newpar[i]].push_back(i);

        vector<int>ans(n,0);
        DFS(0,modified,ans);

        return ans;    
    }
};