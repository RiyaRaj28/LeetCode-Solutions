class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        unordered_set<int>st; 
        int n = A.size();
        vector<int>C(n);
 
        int total_freq = 0; 
        for(int i=0; i<n; i++)
        {
            int freq = 0; 
            if(st.find(A[i]) != st.end()) freq++; 
            else st.insert(A[i]);

            if(st.find(B[i]) != st.end()) freq++; 
            else st.insert(B[i]);

            total_freq += freq; 
            C[i] = total_freq; 
        }
        return C; 
    }
};  