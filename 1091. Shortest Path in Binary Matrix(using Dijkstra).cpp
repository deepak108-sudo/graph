class Solution {
public:
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

    typedef pair<int,pair<int,int>> p;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        {
            return -1;
        }

        vector<vector<int>> result(n,vector<int>(n,INT_MAX));

        priority_queue<p,vector<p>,greater<p>> pq;  //min heap to find minimum distance from (0,0) coordinate

        result[0][0]=0; //distance from source to source is 0
        pq.push({0,{0,0}});
        grid[0][0]=1;  

        while(!pq.empty())
        {
            int currD=pq.top().first;
            auto currCoord=pq.top().second;
            int x=currCoord.first;
            int y=currCoord.second;

            pq.pop();

            for(auto &dir:directions)
            {
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                int dist=1;

                if(new_x>=0 && new_y>=0 && new_x<n && new_y<n && grid[new_x][new_y]==0 && dist+currD<result[new_x][new_y])
                {
                    result[new_x][new_y]=dist+currD;
                    pq.push({dist+currD,{new_x,new_y}});
                    grid[new_x][new_y]=1;
                }
            }

        }

        return result[n-1][n-1]==INT_MAX ? -1 : result[n-1][n-1]+1;
    }
};