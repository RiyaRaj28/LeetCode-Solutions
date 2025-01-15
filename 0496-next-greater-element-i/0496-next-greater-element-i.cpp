class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        //poore family ke liye respect badh gaya 
        // wont be able to look myself in the eye if i let this go this time 
        stack<int>st; 
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>result(n2);
        for(int i=n2-1; i>=0; i--)
        {
            if(st.empty()) result[i] = -1;
            else 
            {
                while(!st.empty() && nums2[st.top()] < nums2[i])
                {
                    st.pop();
                }
                result[i] = st.empty() ? -1 : nums2[st.top()];
            }

            st.push(i);
        }

        // for(int i=0; i<n2; i++) cout << result[i] << " ";
        vector<int>ans(n1);

        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(nums1[i] == nums2[j]) ans[i] = result[j];
            }
        }
        return ans;
    }

};