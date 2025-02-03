class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n = nums.size(); 
        int ans = 0;

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         vector<int>temp; 
        //         bool flag = false; 
        //         set<int>st; 
        //         for(int k=i; k<=j; k++)
        //         {
        //             temp.push_back(nums[k]); 
        //             if(st.find(nums[k]) != st.end()) 
        //             {
        //                 flag = true; 
        //                 break; 
        //             }
        //             else st.insert(nums[k]);
        //         }

        //         if(flag == false)
        //         {
        //             vector<int>temp2 = temp; 
        //             sort(temp2.begin(), temp2.end()); 

        //             vector<int>temp3 = temp; 
        //             sort(temp3.begin(), temp3.end(), greater<int>()); 

        //             if(temp == temp2 || temp == temp3)
        //             {
        //                 if(j-i+1 > ans) ans = j-i+1; 
        //             }  
        //         }

                   
        //     }
        // }
        // return ans; 




       if(nums.size() == 1) return 1; 
       int inc = 1, dec = 1; 
       for(int i=1; i<n; i++)
       {
            if(nums[i]>nums[i-1]) inc++, dec = 1; 
            else if(nums[i] < nums[i-1]) dec++, inc = 1; 
            else inc = 1, dec = 1; 
            ans = max({ans, dec, inc});
       }

       return ans; 





















    }
};