//-------------------T.C : E*V-----------------------

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> result(V,1e8);
        
        result[src]=0;  //distance of source to source is 0
        
        //In Bellman ford iterating V-1 gives the answer
        for(int count=1;count<=V;count++)
        {
            
            for(auto &edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                
                if(result[u]!= 1e8 && result[u]+wt<result[v])
                {
                    if(count==V)
                    {
                        return {-1};
                    }
                    
                    result[v]=result[u]+wt;
                }
            }
        }
        
        //If one more relax(distance decreased) happend then negative cycle
         for(auto &edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                
                if(result[u]!= 1e8 && result[u]+wt<result[v])
                {
                    return {-1};
                }
            }
            
        return result;
    }
};
