class Solution {
    int n;
    void bfs(vector<vector<int>>& isConnected,int u,vector<bool> &isVisited)
    {
        queue<int> q;
        q.push(u);

        isVisited[u]=true;

            while(!q.empty())
            {
                int u=q.front();
                q.pop();

                for(int v=0;v<n;v++)
                {
                    if(isConnected[u][v]==1 && !isVisited[v])
                    {
                        isVisited[v]=true;
                        q.push(v);
                    }
                }
            }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool> isVisited(n,false);

        int count=0;

        for(int i=0;i<n;i++)
        {
            if(!isVisited[i])
            {
                bfs(isConnected,i,isVisited);
                count++;
            }
        }
        return count;
    }
};