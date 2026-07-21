class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto &e : prerequisites){
            int i = e[1], j = e[0];
            adj[i].push_back(j);
            indegree[j]++;
        }
        int processed = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            processed++;
            for(auto &nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        return processed == numCourses;
    }
};
