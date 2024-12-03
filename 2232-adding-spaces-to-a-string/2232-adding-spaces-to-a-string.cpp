class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string str = "";
        int k = 0; 

        for(int i=0; i<s.length(); i++)
        {
            if(k<spaces.size() && i == spaces[k])
            {
                str += " "; 
                k++;
            }

            str += s[i]; 
        }
        
        return str; 
    }
};