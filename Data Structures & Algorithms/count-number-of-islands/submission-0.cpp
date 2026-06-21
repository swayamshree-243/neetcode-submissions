class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n){
        if(m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size()) return;
        if(grid[m][n] == '0') return;
        grid[m][n] = '0';
        dfs(grid, m+1, n);
        dfs(grid, m, n+1);
        dfs(grid, m-1, n);
        dfs(grid, m, n-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
