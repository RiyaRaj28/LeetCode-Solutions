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

    // int maxSum; 

    // int solve(TreeNode* root)
    // {
    //     if(root == NULL) return 0; 
    //     int left = solve(root->left);
    //     int right = solve(root->right);

    //     int only_ek_acha = max(left, right) + root->val; 
    //     int only_root_acha = root->val;
    //     int neeche_hi_milgaya = left + right + root->val; 

    //     maxSum = max({ maxSum, only_ek_acha, only_root_acha, neeche_hi_milgaya});

    //     return max(only_ek_acha, only_root_acha);
    // }

    // int maxPathSum(TreeNode* root) 
    // {
    //     maxSum = INT_MIN; 

    //     solve(root);

    //     return maxSum; 
    // }

    // int maxPath(TreeNode* root, int &maxi)
    // {
    //     if(root == NULL) return 0; 

    //     int left = max(0, maxPath(root->left, maxi));
    //     int right = max(0, maxPath(root->right, maxi));

    //     maxi = max(maxi, root->val + left + right);
        
    //     return max(left, right) + root->val; 
    // }

    // int maxPathSum(TreeNode* root) 
    // {
    //    int maxi = INT_MIN; 

    //    maxPath(root, maxi);

    //    return maxi; 
    // }


  //maximum path will 

  int maxSum; 

  int solve(TreeNode* root)
  {
    if(root == NULL) return 0; 
    int l = solve(root->left); 
    int r = solve(root->right); 

    int root_hi_acha = root->val; 
    int koi_ek_acha = max(l, r) + root->val;
    int neeche_mil_gaya_ans = l + r + root->val; 

    maxSum = max({maxSum, root_hi_acha, koi_ek_acha, neeche_mil_gaya_ans}); 
 
    return max(koi_ek_acha, root_hi_acha); 

  }

    int maxPathSum(TreeNode* root) 
    {
        maxSum = INT_MIN; 

        solve(root); 

        return maxSum; 
    }


};