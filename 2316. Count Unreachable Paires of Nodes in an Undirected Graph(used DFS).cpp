class Solution {
    int dfs(unordered_map<int,vector<int>> &adj,int u,vector<bool> &visited,int &cnt)
    {
        visited[u]=true;
        cnt++;

        for(auto &v:adj[u])
        {
            if(!visited[v])
            {
                dfs(adj,v,visited,cnt);
            }
        }

        return cnt;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);
        vector<int> freq;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int cnt=0;
                freq.push_back(dfs(adj,i,visited,cnt));
            }
        }

        //Calculate final answer
        long long result=0;
        int remainingNode=n;
        for(int i=0;i<freq.size();i++)
        {
            int size=freq[i];
            result+=(long long)size*(remainingNode-size);
            remainingNode-=size;
        }

        return result;
    }
};