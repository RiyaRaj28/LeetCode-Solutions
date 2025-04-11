class Solution {
public:

    long long solve(string num, string suff, int lim)
    {
        int slen = suff.length(); 
        int nlen = num.length(); 
        long long cnt = 0; 

        if (nlen < slen) {
        return 0;
        }

        string org_suff = num.substr(nlen-slen); 
        int rem = nlen - slen; 

        for(int i=0; i<nlen-slen; i++)
        {
            // int fdig = num[i]; 
            int fval = num[i] - '0'; 
            if(fval <= lim) 
            {
                cnt += (fval) * pow(lim+1, rem-i-1);
                // return cnt; 
            }
            else 
            {
                cnt += pow(lim+1, rem-i);
                return cnt; 
            } 

            // cnt += fval * pow(lim+1, rem-i-1); 
        } 
        if(suff <= org_suff) cnt += 1; 

        return cnt; 
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        string st = to_string(start-1); 
        string fin = to_string(finish); 

        long long first = solve(st , s, limit); 
        long long second = solve(fin, s, limit); 

        return second-first; 
    }
};