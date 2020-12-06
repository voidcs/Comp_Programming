class Solution {

    //PROBLEM LINK
    //https://leetcode.com/problems/pacific-atlantic-water-flow/
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans;
        
        array<int, 2> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        function<bool(int, int)> valid = [&](int x, int y){
            return(x >= 0 && y >= 0 && x < n && y < m);
        };
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        bool p = 0, c = 0;
        function<void(int, int)> dfs = [&](int x, int y){
            vis[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(newX == -1 || newY == -1)
                    p = 1;
                if(newX == m || newY == n)
                    c = 1;
                if(valid(newX, newY) && !vis[newX][newY] && matrix[newX][newY] <= matrix[x][y]){
                    vis[newX][newY] = 1;
                    dfs(newX, newY);
                }
            }
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++)
                    for(int l = 0; l < m; l++)
                        vis[k][l] = 0;
                p = 0, c = 0;
                dfs(i, j);
                if(p == 1 && c == 1)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};