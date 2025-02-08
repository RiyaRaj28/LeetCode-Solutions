class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        // need to extract each part afer a dot and put in a map and increase its count 

        unordered_map<string, int>mpp; 

        for(string s : cpdomains)
        {
            int start = 0; 
            int pos = 0; 

            // while((pos = s.find('.', start)) != string::npos)
            // {
            //     string temp = s.substr(start, pos-start); 
            //     mpp[temp] += 1; 
            //     start = pos + 1; 
            // }

            // string last = s.substr(start); 
            // mpp[last] += 1; 

            int spaceind = s.find(' '); 
            int count = stoi(s.substr(0, spaceind)); 
            string domain = s.substr(spaceind+1); 

            while(true)
            {
                mpp[domain.substr(start)] += count; 

                int nextdot = domain.find('.', start); 

                if(nextdot == string::npos) break; 

                start = nextdot + 1; 
            }
        }

        
            vector<string>ans; 

            for(auto it = mpp.begin(); it != mpp.end(); it++)
            {
                string count = to_string(it->second); 
                string str = it->first; 

                ans.push_back(count + ' ' + str);
            }

        return ans; 

    }
};