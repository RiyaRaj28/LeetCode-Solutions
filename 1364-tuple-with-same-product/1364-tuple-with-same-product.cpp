class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        // int count = 0; 
        // int org_prod = 0; 
        // int dprod = 0; 
        // for(int i=0; i<nums.size(); i++)
        // {
        //     for(int j=0; j<nums.size(); j++)
        //     {
        //         if(j == i) continue; 
        //         else org_prod = nums[i]*nums[j]; 

        //         for(int di=0; di<nums.size(); di++)
        //         {
        //             for(int dj=0; dj<nums.size(); dj++)
        //             {
        //                 if(di == i || dj == j || di == dj || di == j || dj == i) continue; 
        //                 else dprod = nums[di]*nums[dj]; 
        //                 if(dprod == org_prod) count += 8; 

        //             }
        //             // if(dprod == org_prod) count += 8;
        //         }
        //         // if(dprod == org_prod) count += 8;
                
        //     }
        // }

        // return count; 


        // map<int, set<int>>mpp; 
        int n = nums.size();
        int count = 0; 
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         if(j == i) continue; 
        //         else 
        //         {
        //             int prod = nums[i]*nums[j]; 
        //             mpp[prod].insert(i); 
        //             mpp[prod].insert(j); 
        //         }
        //     }
        // }

        // for(auto it=mpp.begin(); it!= mpp.end(); it++)
        // {
        //     if((it->second.size())%4 == 0) count += ((it->second.size())/2)*8;  
        // }

        // return count;

        map<int, int>mpp; 
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int prod = nums[i]*nums[j]; 
                mpp[prod]++;  

                if(mpp[prod]>1) count += (mpp[prod]-1)*8; 
                
            }
        }
        return count; 
        
    }
};