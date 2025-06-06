
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int,vector<pair<int,int>>> adj;   //u->{v,w}
        
        //Create Adjacency list
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
        }
        
        //min-heap to get the minimum distance at top
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;     //miin_heap
        
        //Distance from src to each node
        vector<int> result(V,INT_MAX);
        
        result[src]=0;      //src to src distance 0
        pq.push({0,src});   //pushed in priority queue
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &v:adj[node])
            {
                int adjNode=v.first;
                int wt=v.second;
                
                if(d+wt<result[adjNode])    //if distance to that node is less then update result and push to priority queue
                {
                    result[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        return result;
    }
};