class Solution {
    char find(char i,unordered_map<char,char>& parent)
    {
        if(i==parent[i])
        {
            return i;
        }

        return parent[i]=find(parent[i],parent);
    }
    void uni(char a,char b,unordered_map<char,int>& rank, unordered_map<char,char>& parent)
    {
        int a_parent=find(a,parent); //a
        int b_parent=find(b,parent); //b

        if(a_parent==b_parent)
        {
            return;
        }
        else if(rank[a_parent]>rank[b_parent])
        {
            parent[b_parent]=a_parent;
        }
        else if(rank[b_parent]>rank[a_parent])
        {
            parent[a_parent]=b_parent;
        }
        else{
            parent[b_parent]=a_parent;
            rank[a_parent]++;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {

        // push all != string to the last(sorted that is == first then !=) to ensure first all union operation take place failing this test cases ----- ["a==b","b!=c","c==a"]
        sort(equations.begin(), equations.end(), [](const string& a, const string& b) {
        return a[1] > b[1];  // Descending: '==' (61) comes before '!=' (33)
        });


        //assigned parent of themselves
        unordered_map<char,char> parent(26);
        for(char ch='a';ch<='z';ch++)
        {
            parent[ch]=ch;
        }

        //initially the rank of all will be 0
        unordered_map<char,int> rank(26);
        for(char ch='a';ch<='z';ch++)
        {
            rank[ch]=0;
        }
        
        for(int i=0;i<equations.size();i++)
        {
            //Destructured all the element of each string
            int a=equations[i][0];
            int b=equations[i][1];
            int c=equations[i][2];
            int d=equations[i][3];

            if(b=='=')
            {
                uni(a,d,rank,parent);    //(=)Both are equal so union them 
            }
            else{
                char a_parent=find(a,parent);     //(!)if both have same parent return false because they are actually equal
                char b_parent=find(d,parent);

                if(a_parent==b_parent)  //if both have same parent return false
                {
                    return false;
                }
            }

        }
        return true;
    }
};