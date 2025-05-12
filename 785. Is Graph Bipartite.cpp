class Solution {
    bool isBipartiteDFS(vector<vector<int>>& graph,int curr,vector<int> &color,int currColor)
    {
        color[curr]=currColor;

        for(int &v:graph[curr])
        {
            //if neighbour node are same colored then return false(it is the main root where false arrise)
            if(color[v]==color[curr])
            {
                return false;
            }

            //invert the color(take other color) becoz going to color neighbour
            int colorV=1-currColor;

            //If node is not coloured only then call isBipartiteDFS
            if(color[v]==-1)
            {
                if(isBipartiteDFS(graph,v,color,colorV)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        //Create adjacency list
        int v=graph.size();

        //First all node are transparent(not colored)
        vector<int> color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                //If from any branch returned false then it will be false
                if(isBipartiteDFS(graph,i,color,1)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};