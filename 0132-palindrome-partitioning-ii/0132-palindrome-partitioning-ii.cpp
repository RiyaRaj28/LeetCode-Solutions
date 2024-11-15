class Solution {
public:
    bool dp[2001][2001];
    int solve(string &s,int i,vector<int>&cuts){
        if(dp[i][s.length()-1])return cuts[i]=0;
        if(cuts[i]!=1e9)return cuts[i];
        int ans=1e9;
        for(int idx=i;idx<s.length();idx++){
            //if its a palindrome we can make a cut
            if(dp[i][idx]){
                ans=min(ans,1+solve(s,idx+1,cuts));
            }
        }
        return cuts[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        memset(dp,false,sizeof(dp));
        // filling dp table which will tell substring 
        // i to j is palindrome or not     
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j)dp[i][j]=true;
                else if(i+1==j)dp[i][j]=(s[i]==s[j]);
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
            }
        }
        vector<int>cuts(n,1e9);
        return solve(s,0,cuts);
    }
};