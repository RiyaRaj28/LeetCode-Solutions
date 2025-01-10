class Solution {
public:

    vector<int> parent;
    vector<int> rank; 

    int find(int x)
    {
        if(parent[x] == x) return x; 

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par) return;

        if(rank[x_par] > rank[y_par]) parent[y_par] = x_par;
        else if(rank[y_par] > rank[x_par]) parent[x_par] = y_par; 
        else 
        {
            parent[y_par] = x_par;
            rank[x_par]++; 
        }

    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size(); 
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;

        unordered_map<string, int>mpp; 

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()) mpp[mail] = i; 
                else Union(mpp[mail], i);
            }
        }

        // J1 -> 1
        // J2 -> 1

        // now we have to form the vector of string of the same nodes 

        // in the map we have the mails and their indexes present
        // if the indexes share the same parent that is also done 

        vector<vector<string>>mergedMails(n); 
        for(auto it : mpp)
        {
            string mail = it.first; 
            int node = find(it.second); 
            
            mergedMails[node].push_back(mail);
        }
        vector<vector<string>>ans; 

        for(int i=0; i<n; i++)
        {
            if(mergedMails[i].size() != 0)
            {
                string name = accounts[i][0];
                vector<string>temp; 
                temp.push_back(name); 
                sort(mergedMails[i].begin(), mergedMails[i].end());

                for(int j=0; j<mergedMails[i].size(); j++)
                {
                    temp.push_back(mergedMails[i][j]);
                }
                ans.push_back(temp);
            } 
        }
        return ans; 
    }
};