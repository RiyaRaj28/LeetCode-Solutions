class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        set<string>st; 
        for(auto it: wordList) st.insert(it); 

        queue<pair<int, string>>q; 

        q.push({1, beginWord});

        while(!q.empty())
        {
            string word = q.front().second; 
            int step = q.front().first;
            q.pop();

            for(int i=0; i<word.length(); i++)
            {
                char org = word[i];
                for(char ch='a'; ch<='z'; ch++)
                {
                    word[i] = ch;

                    if(st.find(word) != st.end())
                    {
                        if(word == endWord)
                        {
                        return step+1;
                        } 
                        q.push({step+1, word});
                        st.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};