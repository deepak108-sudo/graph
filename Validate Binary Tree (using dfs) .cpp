class Solution {
    void dfs(int u,unordered_map<int,vector<int>> &adj,vector<int> &visited,int &cnt){
        
        visited[u]=true;
        cnt++;

        for(int &child:adj[u]){

            if(visited[child]==true){   //early exit if child are visiting twice
                return;
            }
            if(!visited[child]){
                dfs(child,adj,visited,cnt);
            }
        }
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int> childToParent;
        unordered_map<int,vector<int>> adj;

        //-------------------Create adj List and To (find if one child has two parent)----------
        for(int i=0;i<n;i++){
            int node=i;
            int lc=leftChild[i];
            int rc=rightChild[i];

            if(lc!=-1){
                if(childToParent.find(lc)!=childToParent.end()){    //Already assigned parent to lc then again is assigining means two parent
                    return false;
                }

                adj[i].push_back(lc);

                childToParent[lc]=node;
            }

            if(rc!=-1){
                if(childToParent.find(rc)!=childToParent.end()){
                    return false;
                }

                adj[i].push_back(rc);
                childToParent[rc]=node;
            }
        }


        //------------------(Find Root)-----------------------
        int root=-1;
        for(int i=0;i<n;i++){
            
            if(childToParent.find(i)==childToParent.end())
            {
                if(root != -1){ // Already root assigned mean condition of two root
                    return false;
                }
               root=i;
            }
        }

        if(root==-1){   //Even to now root is not there means all node have parent hence no root
            return false;
        }

        //--------------Find cycle and ensure that all node in visited by root
        vector<int> visited(n,false);
    
        int cnt=0;
        dfs(root,adj,visited,cnt);

        return n==cnt;
    }
};