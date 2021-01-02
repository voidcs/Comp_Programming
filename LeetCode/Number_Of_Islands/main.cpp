class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/number-of-islands/submissions/
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        function<bool(int, int)> valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        function<void(int, int)> dfs = [&](int x, int y){
            vis[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '1'){
                    vis[nx][ny] = 1;
                    dfs(nx, ny);
                }
            }
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};