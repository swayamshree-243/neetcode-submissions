class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if(grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int area = 0;
        for(int k = 0; k < 4; k++){
            area += dfs(grid, i+dx[k], j+dy[k]);
        }
        return 1 + area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }
};
