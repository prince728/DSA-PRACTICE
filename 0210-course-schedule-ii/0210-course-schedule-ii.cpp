class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i];
                indeg[neighbour]--;
                if (indeg[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};

    }
};