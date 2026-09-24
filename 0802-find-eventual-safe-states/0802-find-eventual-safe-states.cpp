class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                revGraph[neighbor].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

             safe[node] = true; 

            for (int prevNode : revGraph[node]) {
                outdegree[prevNode]--;
                if (outdegree[prevNode] == 0) {
                    q.push(prevNode);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};