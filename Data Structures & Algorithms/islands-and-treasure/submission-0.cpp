class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == INT_MAX){
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};
