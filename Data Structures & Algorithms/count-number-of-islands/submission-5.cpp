class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i , int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for(int d = 0; d < 4; d++){
            dfs(grid, i + dx[d], j + dy[d]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
