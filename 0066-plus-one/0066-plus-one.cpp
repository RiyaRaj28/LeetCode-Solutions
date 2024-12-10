class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        // DOES NOT WORK, CAUSES ERROR WITH DATA TYPE 
        // if(digits.size() == 0) return digits; 
        // double num = 0; 
        // int i = 0; 
        // int n = digits.size(); 
        // while(i < n)
        // {
        //     num = num*10 + digits[i];
        //     i++; 
        // }

        // num = num + 1; 

        // double rev_num = 0;
        // vector<int>vec; 
        // vector<int>rev_vec; 

        // while(num != 0)
        // {
        //     double dig = num%10; 
        //     rev_vec.push_back(dig); 

        //     rev_num = rev_num*10 + dig; 
            
        //     num = num/10; 
        // }

        // reverse(rev_vec.begin(), rev_vec.end()); 

        // return rev_vec; 

        int n = digits.size(); 
        for(int i = n-1; i>=0; i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++; 
                return digits; 
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1); 
        return digits; 
    }
};