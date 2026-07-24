class Solution {
public:
    void dfs(vector<vector<int>>& a,int i,int j,int o,int c){
        if(i<0||j<0||i==a.size()||j==a[0].size()||a[i][j]!=o) return;
        a[i][j]=c;
        dfs(a,i+1,j,o,c);
        dfs(a,i-1,j,o,c);
        dfs(a,i,j+1,o,c);
        dfs(a,i,j-1,o,c);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
            dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};