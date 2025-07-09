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

    int sum = 0, maxlevel = INT_MIN;

    void func(TreeNode* root, int level)
    {
        if(root == NULL) return;

        if(level == maxlevel) sum += root->val;
        if(level > maxlevel) 
        {
            maxlevel = level; 
            sum = root->val; 
        }

        if(root->left) func(root->left, level+1);
        if(root->right) func(root->right, level+1);
    }

    int deepestLeavesSum(TreeNode* root) {

        func(root, 1);
        return sum; 
    }
};