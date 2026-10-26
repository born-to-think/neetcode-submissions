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
    int max_sum = -1001;

    int max_from_root(TreeNode* root)
    {
        if(!root) return 0;

        int max_from_left_subroot  = max_from_root(root->left );
        int max_from_right_subroot = max_from_root(root->right);
        
        int val1 = root->val +  max( { 0,max_from_left_subroot, max_from_right_subroot } ) ;
        int val2 = max_from_left_subroot + root->val + max_from_right_subroot ;
        
        max_sum = max( {max_sum, val1, val2 } );

        return val1;
    }

    int maxPathSum(TreeNode* root) {
        max_sum = -1001;
        max_from_root(root);
        return max_sum;
    }
};