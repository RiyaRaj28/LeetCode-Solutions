class Solution {
public:
    const int MOD = 1e9+7; 
    bool isSame(vector<int>&arr, vector<int>&brr)
    {   
        int i = arr.size()-1; 
        int check = true; 
        while(i>=0)
            {
                if(arr[i] == brr[i]) continue;
                else 
                {
                    check = false; 
                    break;
                }
                i--; 
            }
        if(check == true) return true;
        return false;
    }

    void Sort(vector<int>arr, vector<int>&ans)
    {
    int n = arr.size();
    // vector<int>ans(n); 
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++) ans[i] = arr[i];
    // return ans; 
    }

    long long safeAdd(long long a, long long b)
    {
        long long sum = (long long)(a + b);
        return sum;
    }

    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        //if both are same return 0 
        if(isSame(arr, brr)) return 0; 
        long long total = 0; 
        int n = arr.size();

        long long ttotal = 0; 
        //without rearr
        {
            for(int i=0; i<arr.size(); i++)
            {
                ttotal = safeAdd(ttotal, abs(arr[i] - brr[i]));
            }
        }

        vector<int>sarr(n); 
        vector<int>sbrr(n); 
        
        Sort(arr, sarr);
        Sort(brr, sbrr);

        if(!isSame(sarr, arr) || !isSame(sbrr, brr)) total = safeAdd(total, k); 

        for(int i=0; i<sarr.size(); i++)
            {
                total = safeAdd(total, abs(sarr[i] - sbrr[i]));
            }

        if(total<ttotal) return total;
        return ttotal;
        // return min(total, ttotal); 
    }
};