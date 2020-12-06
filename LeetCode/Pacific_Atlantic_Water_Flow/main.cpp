class Solution {

    //PROBLEM LINK
    //https://leetcode.com/problems/pacific-atlantic-water-flow/
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        if(!m)
            return ans;
        int n = matrix[0].size();
        if(!n)
            return ans;
        
        array<int, 2> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        function<bool(int, int)> valid = [&](int x, int y){
            return(x >= 0 && y >= 0 && x < m && y < n);
        };
        
        vector<vector<int>> visPacific(m, vector<int>(n, 0));
        vector<vector<int>> visAtlantic(m, vector<int>(n, 0));
        
        function<void(int, int, int)> dfs = [&](int x, int y, int ocean){
            if(ocean)
                visPacific[x][y] = 1;
            else
                visAtlantic[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(ocean){
                    if(valid(newX, newY) && !visPacific[newX][newY] && matrix[newX][newY] >= matrix[x][y]){
                            visPacific[newX][newY] = 1;
                            dfs(newX, newY, ocean);
                    }
                }
                else{
                    if(valid(newX, newY) && !visAtlantic[newX][newY] && matrix[newX][newY] >= matrix[x][y]){
                            visAtlantic[newX][newY] = 1;
                            dfs(newX, newY, ocean);
                    }
                }
                
            }
        };
        for(int i = 0; i < m; i++){
            dfs(i, 0, 1);
            dfs(i, n-1, 0);
        }
        for(int i = 0; i < n; i++){
            dfs(0, i, 1);
            dfs(m-1, i, 0);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visPacific[i][j] && visAtlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};