class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        //equal pos, neg 
        // maintain pos and neg indices 
        // int n = nums.size(); 
        // vector<int>ans(n, 0);

        // int negi = 1, posi = 0; 
        
        // for(int i=0; i<n; i++)
        // {
        //     if(nums[i] > 0) 
        //     {
        //         ans[posi] = nums[i];
        //         posi += 2;
        //     }
        //     else 
        //     {
        //         ans[negi] = nums[i];
        //         negi += 2;
        //     }
        // }
        // return ans; 


        // feed according to whichever is lesser and whichever is more 

        int n = nums.size(); 
        int pos = 0, neg = 0; 
        vector<int>posa; 
        vector<int>nega; 
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0) 
            {
                posa.push_back(nums[i]); 
                pos++; 
            }
            else 
            {
                nega.push_back(nums[i]); 
                neg++; 
            }
        }

        // if neg > pos 
        // fill till the pos indexes, then we go to the neg indexes 
        vector<int>ans(n); 


        if(pos>=neg)
        {
            // ans[2*i] = pos[i]
            // ans[2*i + 1] = neg[i]
            int ind = 0; 
            for(ind=0; ind<neg; ind++)
            {
                ans[2*ind] = posa[ind]; 
                ans[2*ind + 1] = nega[ind]; 
            }

            for(int j=neg; j<pos; j++)
            {
                ans[ind++] = posa[j]; 
            }

        }
        else
        {
            int ind = 0; 
            for(ind=0; ind<pos; ind++)
            {
                ans[2*ind] = posa[ind]; 
                ans[2*ind + 1] = nega[ind]; 
            }

            for(int j=pos; j<neg; j++)
            {
                ans[ind++] = nega[j]; 
            }

        }

        return ans; 
    }
};