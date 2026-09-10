class Solution { 
public: 
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        vector<vector<int>> adj(n); 
        for (int i = 0; i < relations.size(); i++) { 
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1); 
        } 
        
        vector<int> indeg(n, 0); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) { 
                indeg[adj[i][j]]++; 
            } 
        }

        vector<int> dist(n, 0); 
        queue<int> q; 
        int ans = 0; 
        
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i); 
                dist[i] = time[i]; 
                ans = max(ans, dist[i]);
            }
        }
        
        while(!q.empty()){ 
            int size = q.size(); 
            for(int i = 0; i < size; i++){ 
                int val = q.front(); 
                q.pop(); 
                
                for(int j = 0; j < adj[val].size(); j++){ 
                    int neighbor = adj[val][j];
                    
                    dist[neighbor] = max(dist[neighbor], dist[val] + time[neighbor]);
                    ans = max(ans, dist[neighbor]);
                    
                    indeg[neighbor]--; 
                    if(indeg[neighbor] == 0) {
                        q.push(neighbor); 
                    }
                } 
            } 
        } 
        return ans; 
    } 
};
