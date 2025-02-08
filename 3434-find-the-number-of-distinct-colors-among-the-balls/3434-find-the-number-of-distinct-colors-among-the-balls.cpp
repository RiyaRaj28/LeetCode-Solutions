class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        // vector<int>hash(limit+1, -1); 
        int n = queries.size(); 
        // vector<int>ans; 
        // set<int>st; 
        // for(int i=0; i<n; i++)
        // {
        //     if(hash[queries[i][0]]!=-1) st.erase(hash[queries[i][0]]);
            
        //     hash[queries[i][0]] = queries[i][1]; 
        //     // if(st.find(queries[i][1]) != st.end()) st.erase(queries[i][1]);

        //     st.insert(queries[i][1]); 

        //     ans.push_back(st.size());
        // }
        // return ans;  

        map<int, int>indtocol;
        map<int, set<int>>coltoind;  

        vector<int>ans;  

        for(int i=0; i<n; i++)
        {
            int index = queries[i][0]; 
            int col = queries[i][1]; 
            if(!indtocol.count(index))
            {
                indtocol[index] = col; 
                coltoind[col].insert(index); 
            }
            else
            {      
                int old_col = indtocol[index];   
                coltoind[old_col].erase(index); 

                // if(!coltoind.count(indtocol[index])) coltoind.erase(indtocol[index]);
                if(coltoind[old_col].empty()) coltoind.erase(old_col); 

                indtocol[index] = col; 
                coltoind[col].insert(index); 
            }

            ans.push_back(coltoind.size()); 
        }

        return ans; 

    }
};
