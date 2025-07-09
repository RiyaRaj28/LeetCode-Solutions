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
    int maxsum; 
    int solve(TreeNode* root)
    {
        if(root == NULL) return 0; 

        int l = solve(root->left); 
        int r = solve(root->right); 

        int root_hi_acha = root->val;
        int koi_ek_acha = max(l,r) + root->val; 
        int neeche_mil_gaya = l + r + root->val; 

        maxsum = max({maxsum, root_hi_acha, koi_ek_acha, neeche_mil_gaya}); 

        return max(koi_ek_acha, root_hi_acha);
    }


    int maxPathSum(TreeNode* root) 
    {
        maxsum = INT_MIN; 
        if(root == NULL) return 0; 

        solve(root); 
        return maxsum;  
    }
};