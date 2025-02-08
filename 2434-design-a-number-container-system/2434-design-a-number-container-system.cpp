class NumberContainers {
public:
    map<int, int>indtonum;
    map<int, set<int>>numtoind; 

    NumberContainers() {
        
    }
    
    void change(int index, int number) 
    {

        if(!indtonum.count(index))
        {
            indtonum[index] = number; 
            numtoind[number].insert(index); 
        }
        else
        {
            // int num = indtonum[index]; 

            // //now remove this index in the map from that num 
            // auto it = numtoind.find(num); 
            // (it->second).erase(index); 

            // if((it->second).empty()) numtoind.erase(it); 

            // indtonum[index] = number; 
            // numtoind[number].insert(index);            

            numtoind[indtonum[index]].erase(index); 
            indtonum[index] = number; 
            numtoind[indtonum[index]].insert(index); 
        }

        // if(indtonum.find(index) != indtonum.end())
        // {
        //     //there is an elemtn at that index already 
        //     int num = indtonum[index]; 

        //     //now remove this index in the map from that num 
        //     auto it = numtoind.find(num); 
        //     (it->second).erase(index); 

        //     if((it->second).empty()) numtoind.erase(it); 

        //     indtonum[index] = number; 
        //     numtoind[number].insert(index); 
        // }
        // else 
        // {
        //     indtonum[index] = number; 
        //     numtoind[number].insert(index); 
        // }
    }
    
    int find(int number) {
        
        if(numtoind[number].size() == 0) return -1; 
        return *numtoind[number].begin(); 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */