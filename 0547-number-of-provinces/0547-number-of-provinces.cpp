class Solution {
public:
void dfs(int node,vector<bool>&visited,vector<int>adj[]){
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            visited[adj[node][i]]=1;
            dfs(adj[node][i],visited,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0,n=isConnected.size();

        vector<int>adj[n];
        vector<bool>visited(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,visited,adj);
            }
        }
        
        return ans;
    }
};