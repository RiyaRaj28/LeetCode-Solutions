class Solution {
public:
    const int MOD = 1e9+7; 
    vector<int> NSR(vector<int>&arr)
    {
        int n = arr.size();
        vector<int>nsr(n);

        stack<int>st; 
        for(int i=n-1; i>=0; i--)
        {
            if(st.empty()) nsr[i] = n;
            else
            {
                while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
                nsr[i] = st.empty() ? n : st.top();
            } 
            st.push(i);
        }

        // for(int i=0; i<n; i++)
        // {
        //     cout << nsr[i] << " ";
        // }
        // cout << "\n";

        return nsr; 
    }

    vector<int> NSL(vector<int>&arr)
    {
        int n = arr.size();
        vector<int>nsl(n); 

        stack<int>st; 
        for(int i=0; i<n; i++)
        {
            if(st.empty()) nsl[i] = -1; 
            else
            {
                while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
                nsl[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        // for(int i=0; i<n; i++)
        // {
        //     cout << nsl[i] << " ";
        // }
        // cout << "\n";

        return nsl; 
    }

    int sumSubarrayMins(vector<int>& arr) 
    {
        vector<int> nsl = NSL(arr);
        vector<int> nsr = NSR(arr);
        long long sum = 0; 

        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            int nsml = nsl[i];
            int nsmr = nsr[i];

            int left = i - nsml;
            int right = nsmr - i; 

            long long prod = left*right; 
            long long total = arr[i]*prod;
            sum = (sum+total)%MOD; 
        }
        return sum; 
    }
};