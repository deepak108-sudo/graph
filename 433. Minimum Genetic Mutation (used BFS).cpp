class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string choices="ACGT";

        unordered_set<string> visited;
        unordered_set<string> bankset(bank.begin(),bank.end());

        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);

        int level=0;

        while(!q.empty())
        {
            int n=q.size();

            while(n--)
            {
                string curr=q.front();
                q.pop();

                if(curr==endGene) return level;

                for(auto &ch:choices)
                {
                    for(int i=0;i<curr.length();i++)
                    {
                        string temp=curr;
                        temp[i]=ch;

                        if(bankset.find(temp)!=bankset.end() && visited.find(temp)==visited.end())
                        {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};