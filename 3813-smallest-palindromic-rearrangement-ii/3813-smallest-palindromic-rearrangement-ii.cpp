class Solution {
public:

    long long ncr(int n, int r, int maxi)
    {
        if(r>n) return 0; 
        r = min(r, n-r); 
        long long res = 1; 

        for(int i=1; i<=r; i++)
        {
            res = (res*(n-r+i))/i; 

            if(res >= maxi) return maxi; 
        }
        return res; 
    }

    long long count_perms(vector<int>counts, int pos, int maxi)
    {
        long long perms = 1; 
        int rem = pos; 

        for(int i=0; i<counts.size(); i++)
        {
            int ways = ncr(rem, counts[i], maxi); 

            perms *= ways;
            if(perms >= maxi) return maxi; 

            rem -= counts[i];  
        }
        return perms; 
    }

    string smallestPalindrome(string s, int k) 
    {
        vector<int>hash(26, 0); 
        for(int i=0; i<s.length(); i++) hash[s[i] - 'a']++; 
        string middle = ""; 
        long long maxi = k+ 1LL; 

        vector<int>half_count(26, 0);
        for(int i=0; i<26; i++)
        {
            if(hash[i]%2 != 0)
            {
                middle = string(1, i + 'a');
            }
            half_count[i] = hash[i]/2; 
        }

        int half_len = s.length()/2; 

        if(count_perms(half_count, half_len, maxi) < k) return "";

        string half_str = ""; 

        for(int pos=0; pos<half_len; pos++)
        {
            for(int c = 0; c<26; c++)
            {
                if(half_count[c] == 0) continue; 

                half_count[c]--; 

                long long perm_with_suff = count_perms(half_count, half_len-pos-1, maxi); 

                if(perm_with_suff < k)
                {
                    k -= perm_with_suff; 
                    half_count[c]++; 
                }
                else
                {
                    half_str += ('a' + c); 
                    break; 
                }
            }
        }

        string rstr = half_str; 
        reverse(rstr.begin(), rstr.end()); 
        string ans = half_str + middle + rstr; 

        return ans;
    }
};

