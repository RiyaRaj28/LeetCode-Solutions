class Solution {
public: 
    int uniqueXorTriplets(vector<int>& nums) {
    // int xorpairs[2048] = {0};

    // int n = nums.size(); 
    // unordered_set<int>st; 

    // for(int k=0; k<n; k++)
    // {
    //     for(int i=0; i<=k; i++)
    //     {
    //             xorpairs[nums[i] ^ nums[k]]++; 
    //     }

    //     for(int j=0; j<=2047; j++)
    //     {
    //         int xorval;
    //         if(xorpairs[j]>0) 
    //         {
    //             xorval = j^nums[k]; 
    //             st.insert(xorval); 
    //         }
    //     }


    // }

    // return st.size();  


    unordered_set<int>st; 
    int n = nums.size(); 
    if(n==1 || n==2) return n;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            st.insert(nums[i]^nums[j]); 
        }
    }
    unordered_set<int>s; 

    
        for(auto num : st)
        {
            for(int i=0; i<n; i++)
        {   
            s.insert(num^nums[i]); 
        }
    }

    return s.size(); 













    }
};