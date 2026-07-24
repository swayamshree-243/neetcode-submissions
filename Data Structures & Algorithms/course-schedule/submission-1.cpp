class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &e : prerequisites){
            int u = e[1], v = e[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int processed = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            processed++;
            for(auto &nei : adj[x]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        return processed == numCourses;
    }
};
