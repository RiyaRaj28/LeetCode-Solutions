class Solution {
public:

    // int recursion(vector<int>&cardPoints, int l, int r, int k, int cnt)
    // {
    //     if(cnt == k-1) return max(cardPoints[l], cardPoints[r]); 

    //     int left = INT_MIN, right = INT_MIN; 
    //     if(r >= 0) right = cardPoints[r] + recursion(cardPoints, l, r-1, k, cnt+1);
    //     if(l<cardPoints.size()-1) left = cardPoints[l] + recursion(cardPoints, l+1, r, k, cnt+1);

    //     return max(left, right); 
    // }

    // int maxScore(vector<int>& cardPoints, int k) 
    // {
    //     int n = cardPoints.size(); 
    //     int sum = 0; 
        
    //     for(int i=0; i<n; i++) sum += cardPoints[i];
    //     if(k == n) return sum; 

    //     return recursion(cardPoints, 0, n-1, k, 0);
    // }


    //  int maxScore(vector<int>& cardPoints, int k) 
    // {
    //     int n = cardPoints.size(); 
    //     int maxsum = 0; 

    //     int l = 0, r = n-1; 
    //     while(l<=k)
    //     {
    //         int leftsum = 0, rightsum = 0; 
    //         for(int i=0; i<l; i++)
    //         {
    //             leftsum += cardPoints[i]; 
    //         }

    //         r = n - (k-l); 
    //         for(int i=r; i<n; i++)
    //         {
    //             rightsum += cardPoints[i]; 
    //         }
    //         maxsum = max(maxsum, leftsum + rightsum);
    //         l++; 
    //     }

    //     return maxsum; 
    // }

    // int maxScore(vector<int>& cardPoints, int k) 
    // {
    //     int n = cardPoints.size(); 

    //     int l = 0, r = n-1; 
    //     int leftsum = 0, rightsum = 0; 
    //     for(int i=0; i<k; i++) leftsum += cardPoints[i]; 
    //     int maxsum = leftsum; 

    //     int rightind = n-1; 
    //     for(int i=k-1; i>=0; i--)
    //     {
    //         leftsum -= cardPoints[i]; 
    //         rightsum += cardPoints[rightind]; 

    //         rightind -= 1; 
    //         maxsum = max(maxsum, leftsum+rightsum);
    //     }

    //     return maxsum; 
    // }

        int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size(); 

        int l = 0, r = n-1; 
        int sum = 0, rightsum = 0; 
        for(int i=0; i<k; i++) sum += cardPoints[i]; 
        int maxsum = sum; 

        int rightind = n-1; 
        for(int i=0; i<k; i++)
        {
            sum = sum - cardPoints[k-1-i] + cardPoints[n-1-i];
            maxsum = max(maxsum, sum);
            
        }

        return maxsum; 
    }

};