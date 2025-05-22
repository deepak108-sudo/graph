class Solution {
    void dfs(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited)
    {
        if(visited[u]==1)
            return;

        visited[u]=true;

        for(int &nei:adj[u])
        {
            if(!visited[nei])
            {
                dfs(adj,nei,visited);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        vector<bool> visited(n,false);
        int group=0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited);
                group++;
            }
        }


        return n-group;
    }
};