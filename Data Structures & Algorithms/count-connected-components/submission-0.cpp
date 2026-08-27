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
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
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
