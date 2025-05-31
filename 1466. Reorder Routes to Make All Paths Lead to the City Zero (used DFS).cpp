class Solution {
    void dfs(unordered_map<int,vector<pair<int,bool>>> &adj,int u,int &cnt,int parent)
    {
        for(auto &v:adj[u]){

            if(v.first!=parent){

                if(v.second==true)    //durr jaa rha flip it
                {
                    cnt++;
                }

                dfs(adj,v.first,cnt,u);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& c) {
        int count=0;

        unordered_map<int,vector<pair<int,bool>>> adj;

        for(auto &edge:c)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back({v,true});         //true->genuine edge, false->dummy edge
            adj[v].push_back({u,false});
        }

        dfs(adj,0,count,-1);    //0 don't have parent so -1

        return count;
    }
};