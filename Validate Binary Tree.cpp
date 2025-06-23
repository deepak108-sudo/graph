class Solution {
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
    
        queue<int> q;
        q.push(root);

        visited[root]=true;
        int cnt=1;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(int &child:adj[curr]){

                if(visited[child]==true){   //In binary tree child would not be visited twice
                    return false;
                }

                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                    cnt++;
                }
            }
        }

        return n==cnt;
    }
};