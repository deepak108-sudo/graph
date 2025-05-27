class Solution {
    void dfs(unordered_map<char,vector<char>> &adj,char ch,vector<bool> &visited,char &mini)
    {
        mini=min(mini,ch);
        visited[ch-'a']=true;

        for(auto &v:adj[ch])
        {
            if(!visited[v-'a'])
            {
                dfs(adj,v,visited,mini);
            }
        }

        return;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        unordered_map<char,vector<char>> adj;
        string result="";
        char mini='z';

        //Created Adjacency List
        for(int i=0;i<s1.size();i++)
        {
            char u=s1[i];
            char v=s2[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //For each character find min_char
        for(char ch:baseStr)
        {
                vector<bool> visited(26,false);     //we don't want to interfarence with previous visited 

                dfs(adj,ch,visited,mini);
                result.push_back(mini);

                mini='z';   //We are passing by reference that's why we are updating agian and again
        }

        return result;
    }
};