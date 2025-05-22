class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;

        int m=maze.size();
        int n=maze[0].size();

        maze[entrance[0]][entrance[1]]='+'; //Marking visited

        q.push({entrance[0],entrance[1]});

        int steps=0;

        while(!q.empty())
        {
            int N=q.size();
            while(N--)
            {
                auto curr=q.front();
                int i=curr.first;
                int j=curr.second;
                q.pop();

                
                //Given:An exit is defined as an empty cell that is at the border of the maze (Boundary check condition)
                if(curr != make_pair(entrance[0],entrance[1]) && (i==0 || i==m-1 || j==0 || j==n-1))
                {
                    return steps;
                }

                //Exploring all direction
                for(auto &dir:directions)
                {
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    //Go for valid cell
                    if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && maze[new_i][new_j]!='+')
                    {
                        q.push({new_i,new_j});  
                        maze[new_i][new_j]='+'; //Mark visited after pushing
                    }
                }
            }
            steps++;    //Just like a wave after traversing all element of one wave in queue
        }
        return -1;
    }
};