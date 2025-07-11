class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size(); 
        int maxleft = height[0];
        int maxright = height[n-1]; 
        int left = 1; 
        int right = n-2;
        int ans = 0; 

        while(left <= right)
        {
            if(maxleft <= maxright)
            {
                ans += max(0, maxleft-height[left]);
                maxleft = max(maxleft, height[left]); 

                left++;
            }
            else
            {
                ans += max(0, maxright-height[right]); 
                maxright = max(maxright, height[right]); 

                right--;
            }
        }
        return ans; 
        
    }
};