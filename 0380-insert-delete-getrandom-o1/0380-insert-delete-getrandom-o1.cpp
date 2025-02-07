class RandomizedSet {
public:
    // unordered_set<int>st; 
    vector<int>vec;
    int index = 0;  
    unordered_map<int, int>mpp; 

    // map : val -> ind

    RandomizedSet() {
    }
    
    bool insert(int val) {

        //adds in set if not present and returns true else false 
        // if(st.find(val) == st.end()) 
        // {
        //     st.insert(val); 
        //     return true; 
        // }

        // return false; 

        if(mpp.find(val) == mpp.end())
        {
            vec.push_back(val); 
            mpp[val] = vec.size()-1; 

            return true; 
        }

        return false;
    }
    
    bool remove(int val) {

        // removes and trye else f 
        // if(st.find(val) != st.end()) 
        // {
        //     st.erase(val); 
        //     return true; 
        // }
        // return false; 

        if(mpp.find(val) != mpp.end())
        {
            // int temp = mpp[val]; 
            // mpp[val] = mpp[vec.back()]; 
            // mpp[vec.back()] = temp; 

            auto it = mpp.find(val); 
            vec[it->second] = vec.back(); 
            vec.pop_back(); 
            mpp[vec[it->second]] = it->second;
            mpp.erase(val);  
 
            return true; 
        }
        
        return false; 
    }
    
    int getRandom() {
        // returns a random element 
        // vector<int>vec(st.begin(), st.end()); 

        int randind = rand() % vec.size();

        return vec[randind]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */