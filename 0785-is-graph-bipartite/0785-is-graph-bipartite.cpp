class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        queue<int> q;

        for (int j = 0; j < graph.size(); j++) {
            if (color[j] == -1) {
                q.push(j);
                color[j] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int i = 0; i < graph[node].size(); i++) {
                        int neighbour = graph[node][i];
                        if (color[neighbour] == -1) {
                            color[neighbour] = (color[node] + 1) % 2;
                            q.push(neighbour);
                        } else if (color[neighbour] == color[node])
                            return 0;
                    }
                }
            }
        }

        return 1;
    }
};