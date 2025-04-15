class Solution {
public:

    int higher(int num)
    {
        int x = 0; 

        while(num >= pow(2,x))
            {
                x += 1; 
            }

        return x; 
    }
    int uniqueXorTriplets(vector<int>& nums) {

        // unordered_set<int>st; 
        // int n = nums.size(); 
        // for(int i=0; i<n; i++) st.insert(nums[i]); 

        
        // for(int i=0; i<n; i++)
        //     {
        //         for(int j=i+1; j<n; j++)
        //             {
        //                 for(int k=j+1; k<n; k++)
        //                     {
        //                             st.insert(nums[i]^nums[j]^nums[k]);   
        //                     }
        //             }
        //     }

        // return st.size(); 

        int n = nums.size(); 
        if(n == 1) return 1; 
        if(n == 2) return 2; 

        int power =  higher(n); 
        return pow(2, power); 
        
    }
};