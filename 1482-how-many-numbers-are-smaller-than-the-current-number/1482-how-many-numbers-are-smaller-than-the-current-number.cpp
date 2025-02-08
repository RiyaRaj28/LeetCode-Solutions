class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& numbers) {

        unordered_map<int, int>mpp; 
        vector<int>nums = numbers; 
        sort(nums.begin(), nums.end()); 
    
        int n = nums.size(); 
        for(int i=0; i<n; i++)
        {
            int j = i-1; 
            int cnt = 0; 

            while(j>=0)
            {
                if(nums[j] != nums[i]) cnt += 1; 
                j -= 1; 
            }

            mpp[nums[i]] = cnt; 
        }

        vector<int>ans; 
        for(int i=0; i<n; i++)
        {
            int num = numbers[i]; 
            ans.push_back(mpp[num]);
        }

        return ans; 
        
    }
};