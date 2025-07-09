/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //check if the root is the lca, or if p is root 
        // or if q is root or root is null then lca

        if(root == NULL || p == root || q == root) return root; 

        TreeNode* left = lowestCommonAncestor(root->left, p, q); 
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 

        if(left == NULL) return right; 
        if(right == NULL) return left; 

        return root; 


        
    }
};