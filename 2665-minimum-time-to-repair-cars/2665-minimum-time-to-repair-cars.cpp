typedef long long ll; 

class Solution {
public:
    bool ispossible(ll time, vector<int>&ranks, int cars)
    {
        ll total = 0; 
        for(int rank : ranks)
        {
            total += sqrt(time/rank); 
        }

        if(total >= cars) return true; 
        return false; 
    }

    long long repairCars(vector<int>& ranks, int cars) 
    {
        ll start = 1, end = (ll)*min_element(ranks.begin(), ranks.end())*cars*cars; 

        while(start < end)
        {
            ll mid = start + (end-start)/2; 

            if(ispossible(mid, ranks, cars)) end = mid; 
            else start = mid+1; 
        }

        return start; 
    }
};