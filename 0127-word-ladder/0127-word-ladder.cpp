class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        // push all the words from the wordlist into the set
        // in the queue, add the first word with the lnth as 1 
        // then pop the word 
        // for each char of the given word, 
        // iterate select the character
        // iterate from a to z and choose one character 
        // find that char in the set 
        // if found, check if its the end word return lnth + 1
        // else if it is found in the set, add it to the queue and 
        // remove from the set 

        queue<pair<string, int>>q; 
        q.push({beginWord, 1}); 

        set<string>st; 
        for(auto it : wordList)
        {
            st.insert(it); 
        }

        while(!q.empty())
        {
            string str = q.front().first; 
            int lnth = q.front().second; 
            q.pop();

            for(int i=0; i<str.length(); i++)
            {
                char ch = str[i]; 
                for(char c = 'a'; c <= 'z'; c++)
                {
                    str[i] = c; 
                    if(st.find(str) != st.end())
                    {
                        if(str == endWord) return lnth+1; 

                        q.push({str, lnth+1}); 
                        st.erase(str); 
                    }
                }
                str[i] = ch; 
            }
        }
        return 0; 
    }
};