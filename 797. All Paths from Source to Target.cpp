class Solution {
    void dfs(vector<vector<int>>& graph,int s,int t,vector<int> &path,
        vector<vector<int>> &result)
    {
        if(s==t)
        {
            result.push_back(path); //return when source and dest. are equal
            return;
        }

        for(auto &neig:graph[s])
        {
            path.push_back(neig);
            dfs(graph,neig,t,path,result);
            path.pop_back();        //Note: The no. of time we push we have to pop same frequency
        }

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        int source=0;
        int target=n-1;
        vector<int> temp;
        vector<vector<int>> result;

        temp.push_back(0);  //Pushed source beforehand

        dfs(graph,source,target,temp,result);

        return result;
    }
};