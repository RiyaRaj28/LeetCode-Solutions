class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {

        int n = arr.size(); 
        int cnt = 0; 

        for(int i=0; i<n; i++)
        {
            int n1 = arr[i]; 
            for(int j=i+1; j<n; j++)
            {

                int n2 = arr[j]; 
                if(abs(arr[i]-arr[j]) > a) continue;  
                for(int k=j+1; k<n; k++)
                {
                    int n3 = arr[k];

                    if(
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                        cnt++; 
                }
            }
        }

        return cnt; 
        
    }
};