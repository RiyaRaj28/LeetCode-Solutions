class Solution {
public:
    
    bool isPrefix(string str, string pref)
    {
        int prelen = pref.length();

        for(int i=0; i<prelen; i++)
        {
            if(str[i] != pref[i]) return false; 
        }
        return true; 
    }

    int prefixCount(vector<string>& words, string pref) {

        int count = 0; 
        for(int i=0; i<words.size(); i++)
        {
            string str = words[i];
            if(isPrefix(str, pref)) count++;
        }
        return count; 
        
    }
};