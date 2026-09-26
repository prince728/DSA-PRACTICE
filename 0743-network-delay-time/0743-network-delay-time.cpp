class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adj[u].push_back({v, time});
        }

        int ans = 0;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node])
                continue;

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;

                if (dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};