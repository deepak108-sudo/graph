class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<int> result(n+1,INT_MAX);

        vector<vector<pair<int,int>>> adj(n+1);
        
        //Create adjacency List
        for(int i=0;i<m;i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];

            adj[u].push_back({v,w});     //Directed Graph
        }

        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        result[k]=0;    //source to source distance

        pq.push({0,k}); //Pushed the shortest distance in queue
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();

            for(auto &v:adj[node])
            {
                int adjDist=v.second;
                int adjNode=v.first;

                if(d+adjDist < result[adjNode])
                {
                    pq.push({d+adjDist,adjNode});
                    result[adjNode]=d+adjDist;
                }
            }
        }

        // result[0]=-1;   //So that i dosen't effect the answer with function
        auto maxi= max_element(result.begin()+1,result.end());  //leave index 0

        return *maxi==INT_MAX ? -1 : *maxi;
        
    }
};