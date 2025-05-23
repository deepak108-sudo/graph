class Solution {
    void dfs(vector<vector<int>>& rooms,int idx, vector<bool> &visited)
    {
        visited[idx]=true;

        for(int &v:rooms[idx])
        {
            if(!visited[v])
            {
                dfs(rooms,v,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);

        visited[0]=true;

        dfs(rooms,0,visited);

        for(bool val:visited)
        {
            if(val==false)  return false;
        }
        return true;
    }
};