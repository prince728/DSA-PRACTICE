class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),0);
        queue<int>q;
        q.push(0);
        visited[0]=1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0;i<rooms[node].size();i++){
                int neighbour= rooms[node][i];
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }
        }

        for(int i=0;i<visited.size();i++){
            if(visited[i]==0) return 0;
        }

        return 1;

    }
};