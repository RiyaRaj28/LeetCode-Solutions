class Solution {
public:
    // bool isPrime(int num)
    // {
    //     for(int i=2; i<num; i++)
    //     {
    //         if(num % i == 0) return false;  
    //     }
    //     return true; 
    // }

    // vector<int> closestPrimes(int left, int right) 
    // {
    //     // int prev_diff = INT_MAX; 
    //     vector<int>ans(2, -1); 
       

    //     // set<int>st; 
    //     // for(int i=left; i<=right; i++) if(isPrime(i)) st.insert(i); 

    //     // for(int i=left; i<=right; i++)
    //     // {
    //     //     int num1 = i; 
    //     //     if(st.find(i) == st.end()) continue; 
        
    //     //     for(int j=i+1; j<=right; j++)
    //     //     {
    //     //         int num2 = j; 
    //     //         if(j == i || st.find(j) == st.end()) continue; 
                

    //     //         if(num2 - num1 < prev_diff) 
    //     //         {
    //     //             prev_diff = num2 - num1; 
    //     //             ans[0] = num1, ans[1] = num2; 
                    
    //     //         }
    //     //         else if(num2 - num1 == prev_diff && num1 < ans[0])
    //     //         {
    //     //             ans[0] = num1, ans[1] = num2; 
    //     //         }
    //     //     }
    //     // }

    //     vector<int>primes(right+1, 0); 

    //     for(int i=2; i<=right; i++)
    //     {
    //         if(primes[i] == 0)
    //         {
    //             for(int ind = i; ind <=right; ind += i) primes[ind] = 1; 
    //         }
    //     }

    //     int num1 = -1, num2 = -1, prev_diff = INT_MAX; 

    //     for(int i=right; i>=left; i--)
    //     {
    //         if(!primes[i]) continue; 
    //         int num = primes[i]; 

    //         if(num2 == -1) 
    //         {
    //             num2 = num;
    //             continue; 
    //         }

    //         if(num1 == -1)
    //         {
    //             num1 = num;
    //             ans[0] = num1;
    //             ans[1] = num2; 
    //             // continue;  
    //         }

    //         num2 = num1; 
    //         num1 = num; 

    //         if(num2 - num1 <= prev_diff) 
    //         {
    //             ans[0] = num1; 
    //             ans[1] = num2; 
    //         }
    //         // else if(nums2 - num1 == prev_diff)
    //     }


    //     return ans; 
    // }

    vector<int> closestPrimes(int left, int right) 
    {
        // int prev_diff = INT_MAX; 
        vector<int>ans(2, -1);
        vector<int>primes(right+1, 0); 
        primes[0] = 1; 
        primes[1] = 1; 

        for(int i=2; i<=right; i++)
        {
            if(primes[i] == 0)
            {
                for(int ind = i+i; ind <=right; ind += i) primes[ind] = 1; 
            }
        }

        // for(int i=2; i<=right; i++)
        // {
        //     if(primes[i] == 0) cout << i << " ";
        // }

        int num1 = -1, num2 = -1, prev_diff = INT_MAX; 

        for(int i=right; i>=left; i--)
        {
            if(primes[i]) continue; 
            int num = i; 

            if(num2 == -1) 
            {
                num2 = num;
                continue; 
            }

            if(num1 == -1)
            {
                num1 = num;
                ans[0] = num1;
                ans[1] = num2;
                prev_diff = num2 - num1;  
                continue;  
            }

            num2 = num1; 
            num1 = num; 

            if(num2 - num1 <= prev_diff) 
            {
                ans[0] = num1; 
                ans[1] = num2; 
                prev_diff = num2 - num1; 
            }
            // else if(nums2 - num1 == prev_diff)
        }


        return ans; 
    }
};