/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int cyclesort(vector<int>arr)
    {
        int n = arr.size(); 
        int swaps = 0; 

        for(int start=0; start<n; start++)
        {
            int pos = start; 
            int item = arr[start];

            for(int i= start+1; i<n; i++)
            {
                if(arr[i] < item) pos++;
            }

            if(pos == start) continue; 
            while(arr[pos] == item) pos++; 

            if(pos != start)
            {
                swap(arr[pos], item); 
                swaps++;
            }

            //rotate the array 
            while(pos != start)
            {
                pos = start;
                for(int i=start+1; i<n; i++)
                {
                    if(arr[i]<item) pos++;
                }

                if(arr[pos] == start) pos++;

                // if(pos == start) continue; 
                while(arr[pos] == item) pos++;

                if(pos != start)
                {
                    swap(arr[pos], item);
                    swaps++; 
                } 

            }
            
        }

        return swaps; 


    }
    int minimumOperations(TreeNode* root) 
    {
        // bfs -> put in a queue 
        // pop first the parent
        // then if the lc and rc are not already in the queue then push them in 

        // doing a bfs here 
        // breadth first search 
        // level wise bfs occurs 
        // 

        queue<TreeNode*>q; 
        vector<vector<int>>ans; 

        q.push(root); 

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;

            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front(); 
                q.pop(); 
                // cout << node->val << "\n"; 
    
                if(node->left) q.push(node->left); 
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
            // cout << level.size() << "size";
        }


        // for(int i=0; i<ans.size(); i++)
        // {
        //     for(int j=0; j<ans[i].size(); j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << "\n"; 
        // }

        int total = 0; 
        for(int i=0; i<ans.size(); i++)
        {
            int var = cyclesort(ans[i]);
            total += var;
        }

        // for(int i=0; i<ans.size(); i++)
        // {
        //     for(int j=0; j<ans[i].size(); j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << "\n"; 
        // }

        return total; 
        
    }
};