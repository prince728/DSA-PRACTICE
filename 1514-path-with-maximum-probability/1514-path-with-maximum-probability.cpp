class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<pair<int,double>>adj[n];

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob= succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        vector<double>prob(n,0.0);
        prob[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});

        while(!pq.empty()){
            double pro = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == end_node) return pro;

            if(pro < prob[node]) continue;

            for(int i=0;i<adj[node].size();i++){
                int neighbour = adj[node][i].first;
                double Neighbourpro = adj[node][i].second;
                
                if(Neighbourpro*prob[node]>prob[neighbour] ){
                    prob[neighbour]=prob[node] * Neighbourpro;
                    pq.push({prob[neighbour], neighbour});
                }

            }
        }

        return prob[end_node];
    }
};