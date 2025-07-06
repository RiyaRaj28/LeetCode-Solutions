class FindSumPairs {
public:

    vector<int>nums1; 
    vector<int>nums2; 
    unordered_map<int, int>mpp2; 

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        this->nums1 = nums1; 
        this->nums2 = nums2; 
        for(int i=0; i<nums2.size(); i++) mpp2[nums2[i]] += 1; 
    }
    
    void add(int index, int val) {

        mpp2[nums2[index]] -= 1; 

        if(mpp2[nums2[index]] == 0) mpp2.erase(mpp2[nums2[index]]); 
        nums2[index] += val; 
        mpp2[nums2[index]] += 1; 
        
    }
    
    int count(int tot) 
    {
        

        int ans = 0; 
        for(int i=0; i<nums1.size(); i++)
        {
            if(mpp2.find(tot - nums1[i]) != mpp2.end())
            {
                ans += mpp2[tot - nums1[i]];
            }
        }
        return ans; 
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */