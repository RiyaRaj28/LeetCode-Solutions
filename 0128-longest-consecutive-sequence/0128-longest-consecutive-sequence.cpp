// class Solution {
// public:

//     bool linear_search(int num, vector<int>&nums)
//     {
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i] == num) return true; 
//         }
//         return false; 
//     }
//     int longestConsecutive(vector<int>& nums) 
//     {
//         //we have to find the next greater element by 
//         //linear search, need to find x+1 in the array in 
//         // the reamining elems from the current one 

//         //be confident 

//         int maxi = 0; 

//         for(int i=0; i<nums.size(); i++)
//         {
//             int el = nums[i];
//             int cnt = 1; 

//             while(linear_search(el+1, nums) == true)
//             {
//                 el = el+1; 
//                 cnt += 1; 
//             }

//             maxi = max(maxi, cnt);
//         }
//         return maxi; 
        
//     }
// };


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) 
//     {
//         //we have to find the next greater element by 
//         //linear search, need to find x+1 in the array in 
//         // the reamining elems from the current one 

//         //be confident 
//         // we will keep a variable last smallest 
//         // and we will check if arr[i]-1 == last smallest, then inc count 

//         int last_smallest = INT_MIN; 
//         int cnt = 1;
//         int maxi = 0; 
//         sort(nums.begin(), nums.end());

//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i]-1 == last_smallest)
//             {
//                 last_smallest = nums[i];
//                 cnt += 1; 
//             }
//             else if(nums[i] != last_smallest)
//             {
//                 last_smallest = nums[i];
//                 cnt = 1; 
//             }
//             maxi = max(maxi, cnt);
//         }
//         return maxi; 
//     }
// };



class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        // insert elements in a set and then perform functions in that 

        unordered_set<int>st; 
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        int longest = 0; 
        for(auto it : st)
        {
            if(st.find(it - 1) == st.end())
            {
                int cnt = 1; 
                int x = it; 
                while(st.find(x+1) != st.end())
                {
                    cnt++; 
                    x = x+1; 
                }
                longest = max(longest, cnt);
            }
        }
        return longest; 
    }
};