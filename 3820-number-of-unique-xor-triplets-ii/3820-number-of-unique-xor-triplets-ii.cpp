class Solution {
public: 
    int uniqueXorTriplets(vector<int>& nums) {
    int xorpairs[2048] = {0};

    int n = nums.size(); 
    unordered_set<int>st; 

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<=k; i++)
        {
                // for (int j = i; j <= k; j++) {
                //     xorpairs[nums[i] ^ nums[j]]++;
                // }
                xorpairs[nums[i] ^ nums[k]]++; 
        }
        
        for(int j=0; j<=2047; j++)
        {
            int xorval;
            if(xorpairs[j]>0) 
            {
                xorval = j^nums[k]; 
                st.insert(xorval); 
            }
        }


    }

    return st.size();  
    }
};