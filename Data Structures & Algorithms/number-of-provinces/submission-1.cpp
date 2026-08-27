class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int k){
        visited[k] = true;
        for(int nei : adj[k]){
            if(!visited[nei]){
                dfs(adj, visited, nei);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};