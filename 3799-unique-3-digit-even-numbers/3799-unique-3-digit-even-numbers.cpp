class Solution {
public:

    int totalNumbers(vector<int>& digits) 
    {
        int n = digits.size(); 
        unordered_set<int>st; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    if(i!=j && j!=k && k!=i)
                    {
                        if(digits[i] != 0)
                        {
                            if(digits[k]%2 == 0)
                            {
                                int num = 100*digits[i] + 10*digits[j] + digits[k];
                                st.insert(num); 
                            }
                        }
                    }
                }
            }
        }

        return st.size(); 

   
        
    }
};