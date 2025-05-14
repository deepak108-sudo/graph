class Solution {
    void dfs(unordered_map<int,vector<int>> &adj,int u,vector<int> &visited)
    {
        if(visited[u]==1)
        {
            return;
        }

        visited[u]=1;

        for(auto &v:adj[u])
        {
            if(!visited[v])
            {
                dfs(adj,v,visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> adj;
        int edges=connections.size();

        if((n-1)>edges) return -1;

        for(int i=0;i<edges;i++)
        {
            int a=connections[i][0];
            int b=connections[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a); 
        }

        int component=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited); 
                component++;        //Each dfs each component
            }
        }

        return (component-1);   //total cable required component-1
        
    }
};