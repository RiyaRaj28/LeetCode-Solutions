class Solution {
public:

    long long fact(long long num)
    {
        long long f = 1; 
        for(int i=1; i<=num; i++)
        {
            f *= i; 
        }
        return f;
    }

    long long countGoodIntegers(int n, int k) 
    {
        int d = (n+1)/2; 

        long long start = pow(10, d-1), end = pow(10,d) - 1; 
        unordered_set<string>st; 
        long long ans = 0; 

        for(long long num=start; num<=end; num++)
        {
            string number; 
            if(n%2 == 0)
            {
                string lh = to_string(num); 
                string rh = lh; 
                reverse(rh.begin(), rh.end()); 

                number = lh + rh; 
            }
            else
            {
                string lh = to_string(num); 
                string rh = lh; 
                reverse(rh.begin(), rh.end()); 

                number = lh + rh.substr(1, rh.length()); 
            }

            if(stoll(number) % k == 0) 
            {
                
                sort(number.begin(), number.end());
                cout << number << endl; 
                st.insert(number); 
            }
        }

        for(string s : st)
        {
            unordered_map<char, int>mpp; 

            for(char c : s)
            {
                mpp[c]++;
            }

            int non_zeros = 0;
             non_zeros = s.length() - mpp['0']; 

            long long denom = 1; 
            for(auto it : mpp) denom *= fact(it.second); 

            ans += ((non_zeros) * (fact(s.length()-1)) / denom); 
        }

        return ans; 
        
    }
};