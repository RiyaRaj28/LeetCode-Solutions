class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size(); 
        int q = queries.size(); 
        // vector<int>ans; 
        unordered_map<int, vector<int>>mpp; 
        
        for(int i=0; i<n; i++) mpp[nums[i]].push_back(i); 

        for(auto &it : mpp)
            {
                // bool poss = false; 
                // int fnum = queries[i]; 
                // int snum = nums[fnum]; 
                // int sind = queries[i]; 

                // for(int i=fnum+1; i<fnum+n; i++)
                //     {
                //         int ind = i%n; 
                //         int num = nums[ind]; 

                //         if(num == snum) 
                //         {
                //             poss = true; 
                //             ans.push_back(i-sind); 
                //             break; 
                //         } 
                //     }

                // if(!poss) ans.push_back(-1); 
                vector<int>temp = it.second; 
                int sz = temp.size(); 
                if(sz == 1)
                {
                    nums[temp[0]] = -1; 
                    continue; 
                }

                for(int i=0; i<sz; i++)
                {
                    int f = temp[(i+1)%sz], b = temp[(i-1+sz)%sz]; 
                    int forward = min(n - abs(f - temp[i]), abs(temp[i]-f));
                    int backward = min(abs(temp[i]-b), n - abs(temp[i]-b));
                    nums[temp[i]] = min(backward, forward);  
                }
            }

            for(int i=0; i<q; i++) queries[i] = nums[queries[i]]; 

        return queries; 
    }
};