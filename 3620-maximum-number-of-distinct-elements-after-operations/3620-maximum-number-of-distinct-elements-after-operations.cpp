class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end()); 
        set<int>st; 

        // for(int i=0; i<num.size())
        // nums[0] = nums[0] - k; 
        // int before = nums[0]; 

        int prev = INT_MIN; 
        // st.insert(nums[0]); 
        for(int i=0; i<nums.size(); i++)
        {
                int num = max(prev+1, nums[i]-k); 
                if(num <= nums[i]+k)
                {
                    st.insert(num); 
                    prev = num; 
                }

                // nums[i]  = num; 
            // }
        }

        return st.size();

        // priority_queue<int>pq; 
        // pq.push(nums[0]-k); 

        // for(int i=1; i<nums.size(); i++)
        // {
        //     int num = pq.top() + 1; 
        //     if(num >= nums[i]-k && num <= nums[i]+k)
        //     {
        //         pq.push(num); 
        //     }
        // }

        // return pq.size()

        
    }
};