class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int p = num1.length(), q = num2.length();
        vector<int>res(p+q, 0);

        int ind1 = 0, ind2 = 0;

        for(int i=p-1; i>=0; i--)
        {
            if(num1[i] == '-') continue;

            int a = num1[i] - '0';
            int carry = 0; 
            ind2 = 0;

            for(int j=q-1; j>=0; j--)
            {
                if(num2[j] == '-') continue;

                int b = num2[j] - '0';

                int sum = a*b + res[ind1+ind2] + carry; 
                res[ind1+ind2] = sum%10;
                carry = sum/10;

                ind2++;
            }

            if(carry>0)
            {
                res[ind1+ind2] += carry;
            }

            ind1++;
        }

        //remove leading 0s
        int i = res.size()-1;
        while(i>=0 && res[i] == 0) i--;

        if(i == -1) return "0";

        string ans = "";
        while(i>=0)
        {
            ans += to_string(res[i]);
            i--;
        }

        return ans; 
        
    }
};