class Solution {
public:
    
    static bool comparator(const string &a, const string &b)
    {
        string contentsA = a.substr(a.find(' ')+1); 
        string contentsB = b.substr(b.find(' ')+1); 

        if(contentsA != contentsB) return contentsA < contentsB; 
        else 
        {
            string identifierA = a.substr(0, a.find(' ')); 
            string identifierB = b.substr(0, b.find(' ')); 
            return identifierA < identifierB; 
        }

    }
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        vector<string>digits; 
        vector<string>strings; 

        for(string s : logs)
        {
            int len = s.length(); 
           
            if(isalpha(s[len-1])) strings.push_back(s); 
            else digits.push_back(s); 
        }

        sort(strings.begin(), strings.end(), comparator); 

        vector<string>ans; 

        for(string s : strings)
        {
            ans.push_back(s); 
        }

        for(string s : digits)
        {
            ans.push_back(s); 
        }

        return ans; 

        
    }
};