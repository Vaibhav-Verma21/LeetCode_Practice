class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origCol=image[sr][sc];
        if(origCol==color) return image;
        dfs(image,sr,sc,origCol,color);
        return image;

    }
void dfs(vector<vector<int>>& image,int r,int c,int origCol,int color){
    if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != origCol) {return;}

    image[r][c]=color;
    dfs(image,r+1,c,origCol,color); //right
    dfs(image,r-1,c,origCol,color); //left
    dfs(image,r,c+1,origCol,color); //bottom
    dfs(image,r,c-1,origCol,color); //top
}
};