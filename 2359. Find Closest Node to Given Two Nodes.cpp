class Solution {
    void dfs(vector<int>& edges,int curr_node,vector<int> &dist,vector<bool> &visited)
    {
        visited[curr_node]=true;

        int v=edges[curr_node];       //Given atmost 1 so no for loop

        if(v!=-1 && !visited[v])
        {
            visited[v]=true;
            dist[v]=1+dist[curr_node];
            dfs(edges,v,dist,visited);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();

        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);

        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        dist1[node1]=0;
        dist2[node2]=0;

        dfs(edges,node1,dist1,visited1);
        dfs(edges,node2,dist2,visited2);


        int resultMin=INT_MAX;
        int MinimumIndex=-1;

        for(int i=0;i<n;i++)
        {
            int maxi=max(dist1[i],dist2[i]);
            if(resultMin>maxi)
            {
                resultMin=maxi;
                MinimumIndex=i;
            }
        }

        return MinimumIndex;
    }
};