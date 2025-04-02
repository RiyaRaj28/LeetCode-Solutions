class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long val = LLONG_MIN; 
        int n = nums.size(); 
        for(int i=0; i<n; i++)
        {
            for(int k=n-1; k>=i; k--)
            {
                for(int j=i+1; j<k; j++)
                {
                    long long temp = (long long)(nums[i] - nums[j])*(long long)nums[k]; 
                    // cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << temp << endl; 

                    if(temp>val) val = temp; 
                }
            }
        }

        return val<0 ? 0 : val;
        
    }
};