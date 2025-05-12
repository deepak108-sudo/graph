class Solution {
    bool bfs(vector<vector<int>>& graph,vector<int> &color,int currNode,int currColor)
    {
        queue<int> q;
        q.push(currNode);
        color[currNode]=currColor;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(int &v:graph[u])
            {
                if(color[u]==color[v])
                {
                    return false;
                }

                if(color[v]==-1)
                {
                    color[v]=1-color[u];
                    q.push(v);
                }
            }

        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int v=graph.size();

      vector<int> color(v,-1);
      for(int i=0;i<v;i++)
      {
        if(color[i]==-1)
        {
            if(bfs(graph,color,i,1)==false)     //take 1-> red and 0 for green
            {
                return false;
            }
        }
      } 
      return true; 
    }
};