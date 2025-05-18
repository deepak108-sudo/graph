class Solution {
public:

    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)  //if where we start are already 1(blocked) then direct return -1
        {
            return -1;
        }

        queue<pair<int,int>> q;
        int level=1;    //first step already level 1

        q.push({0,0});
        grid[0][0]=1;

        while(!q.empty())
        {
            int N=q.size();
            

            while(N--)
            {
                auto curr=q.front();
                q.pop();

                int i=curr.first;
                int j=curr.second;

                if(i==n-1 && j==n-1)
                    {
                        return level;
                    }
            
                for(auto &dir:directions)
                {
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];


                    if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && grid[new_i][new_j]==0)
                    {
                        q.push({new_i,new_j});
                        grid[new_i][new_j]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};