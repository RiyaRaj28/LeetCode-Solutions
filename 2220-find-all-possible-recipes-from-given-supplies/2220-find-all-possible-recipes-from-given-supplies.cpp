class Solution {
public:
    vector<string> findAllRecipes(vector<string>& receipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // unordered_set<string>st; 
        // for(int i=0; i<supplies.size(); i++)
        // {
        //     st.insert(supplies[i]); 
        // }

        // unordered_set<string>rs; 
        // for(int i=0; i<receipes.size(); i++) rs.insert(receipes[i]); 

        // for(int i=0; i<receipes.size(); i++) st.insert(receipes[i]); 
        // vector<string>ans; 

        // for(int i=0; i<receipes.size(); i++)
        // {
        //     bool poss = true; 
        //     // for(int j=0; j<ingredients[i].size(); j++)
        //     // {
        //     //     if(st.find(ingredients[i][j]) == st.end())
        //     //     {
        //     //         poss = false; 
        //     //         break; 
        //     //     }
        //     // }

        //     // if(poss)
        //     // {
        //     //     ans.push_back(receipes[i]); 
        //     // }

        //     unordered_set<string>sttemp; 
        //     for(int j=0; j<ingredients[i].size(); j++)
        //     {


        //         if(st.find(ingredients[i][j]) == st.end())
        //         {
        //             poss = false; 
        //             break; 
        //         }
        //         else
        //         {
        //             if(rs.find(ingredients[i][j]) != rs.end())
        //             {
        //                 for(int k=0; k<receipes.size(); k++)
        //                 {
        //                     if(receipes[k] == ingredients[i][j])
        //                     {
        //                         for(int m=0; m<ingredients[k].size(); m++)
        //                         {
        //                             if(st.find(ingredients[k][m]) != st.end())
        //                             {
        //                                 sttemp.insert(ingredients[k][m]); 
        //                             }
        //                         }

        //                     }
        //                 }
        //             }

        //             sttemp.insert(ingredients[i][j]);
        //         }

        //         if(sttemp.find(receipes[i]) != sttemp.end())
        //         {
        //             poss = false;
        //             break; 
        //         }
        //     }

        //     if(poss) ans.push_back(receipes[i]);       
        // }

        // return ans; 

        unordered_set<string>supps; 
        for(int i=0; i<supplies.size(); i++) supps.insert(supplies[i]); 

        unordered_map<string, vector<string>>mpp; 
        for(int i=0; i<receipes.size(); i++)
        {
            mpp[receipes[i]] = ingredients[i]; 
        }

        bool poss = true; 
        while(poss)
        {
            poss= false; 
            for(auto &rec : receipes)
            {
                if(supps.count(rec)) continue; 

                bool canmake = true; 
                for(auto &ing : mpp[rec])
                {
                    if(!supps.count(ing))
                    {
                        canmake = false; 
                        break; 
                    }
                }

                if(canmake)
                {
                    supps.insert(rec);
                    poss = true; 
                }
            }
        }

        vector<string>ans; 
        for(auto &rec : receipes) 
        {
            if(supps.count(rec)) ans.push_back(rec); 
        }
        return ans; 
    }
};