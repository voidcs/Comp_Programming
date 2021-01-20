class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/regions-cut-by-slashes/
public:
    int regionsBySlashes(vector<string>& grid) {
        int ans = 0;
        int n = grid.size();
        bool vis[n][n][4];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < 4; k++)
                    vis[i][j][k] = 0;
        
        //Check if not visited and within grid
        function<bool(int, int, int)> valid = [&](int row, int col, int type){
            return (row >= 0 && row < n && col >= 0 && col < n && !vis[row][col][type]);  
        };
        
        function<void(int, int, int)> dfs = [&](int i, int j, int type){
            vis[i][j][type] = 1;
            //If type is 0, we can travel up
            if(type == 0 && valid(i-1, j, 2)){
                vis[i-1][j][2] = 1;
                dfs(i-1, j, 2);
            }
            //If type is 1 we can travel right
            else if(type == 1 && valid(i, j+1, 3)){
                vis[i][j+1][3] = 1;
                dfs(i, j+1, 3);
            }
            //If type is 2 we can go down
            else if(type == 2 && valid(i+1, j, 0)){
                vis[i+1][j][0] = 1;
                dfs(i+1, j, 0);
            }
            //If type is 3 we can go left
            else if(type == 3 && valid(i, j-1, 1)){
                vis[i][j-1][1] = 1;
                dfs(i, j-1, 1);
            }
            if(grid[i][j] != '/' && valid(i, j, type^1)){
                vis[i][j][type^1] = 1;
                dfs(i, j, type^1);
            }
            if(grid[i][j] != '\\' && valid(i, j, type^3)){
                vis[i][j][type^3] = 1;
                dfs(i, j, type^3);
            }
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int type = 0; type < 4; type++){
                    //Divide each cell into four sections
                    if(!vis[i][j][type]){
                        dfs(i, j, type);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};