class Solution {
public:
    int find(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(auto &e : edges){
            int u = e[0], v = e[1];
            int pu = find(u, parent), pv = find(v, parent);
            if(pu == pv) return {u, v};
            else{
                parent[pv] = pu; 
            }
        }
        return {};
    }
};
