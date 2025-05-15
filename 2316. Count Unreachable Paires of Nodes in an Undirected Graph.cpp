class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void uni(int x,int y)
    {
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent)
        {
            return;
        }
        else if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent])
        {
            parent[x_parent]=y_parent;
        }
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        int totalNode=n;

        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        
        //Union 
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            if(find(u)!=find(v))
            {
                uni(u,v);
            }
        }

            
        unordered_map<int,int> mp;
        //Find no. of node in particular component
        for(int i=0;i<n;i++)
        {
            int parent=find(i);
            mp[parent]++;
        }

        //To find final result
        long long result=0;
        int remainingNode=n;
        for(auto &it:mp)
        {
            long long size=it.second;
            result+=size*(remainingNode-size);
            remainingNode-=size;
        }

        return result;
    }
};