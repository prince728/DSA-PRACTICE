class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1);
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < adj[node].size(); j++) {
                        int neighbour = adj[node][j];
                        if (color[neighbour] == -1) {
                            color[neighbour] = 1 - color[node];
                            q.push(neighbour);
                        } else if (color[neighbour] == color[node]) {
                            return 0;
                        }
                    }
                }
            }
        }


        return 1;
    }
};