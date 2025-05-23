class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //bfs
        queue<int> q;
        vector<bool> visited(n,false);

        q.push(source);
        visited[source]=true;

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            if(curr==destination)
            {
                return true;
            }

            for(int &neig:adj[curr])
            {
                if(!visited[neig])
                {
                    q.push(neig);
                    visited[neig]=true;
                }
            }
        }
        return false;
    }
};