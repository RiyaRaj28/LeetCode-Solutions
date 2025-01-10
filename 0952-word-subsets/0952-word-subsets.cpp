class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        // a is a subset of b if every letter in a occurs in b 

        // b should be a subset of a 
        // find out those words from set 1 which has all the strings of set 2 

        // unordered_map<char, int>bmpp; 
        // vector<int>hash1(26, 0);
        vector<int>maxCount(26, 0); 

        for(int i=0; i<words2.size(); i++)
        {
            vector<int>hash(26, 0);
            for(char c : words2[i])
            {
                hash[c - 'a']++;
                maxCount[c - 'a'] = max(maxCount[c - 'a'], hash[c - 'a']);
            }
        }

        vector<string>ans; 
        for(int i=0; i<words1.size(); i++)
        {
            bool included = true; 
            vector<int>hash2(26, 0);
            for(char c : words1[i])
            {
                hash2[c - 'a']++;
            }

            for(int i=0; i<26; i++)
            {
                if(maxCount[i] != 0)
                {
                    if(hash2[i] < maxCount[i])
                    {
                        included = false; 
                        break; 
                    }
                }
            }
            if(included) ans.push_back(words1[i]);
        }
        return ans; 
        
    }
};