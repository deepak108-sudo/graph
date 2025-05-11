class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        //Store the edges in adjacency list 0->2,3,1 
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            
            adj[a].push_back(b);
        }
        
        //Find indegree of each Vertex
        vector<int> indegree(V,0);
        for(int u=0;u<V;u++)
        {
            for(int &v:adj[u])
            {
                indegree[v]++;
            }
        }
        
        //indegree 0 push in queue
        int count=0;
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                count++;
            }
        }
        
        //bfs
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(int &v:adj[u])
            {
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count==V)    return false;
        return true;
    }
};