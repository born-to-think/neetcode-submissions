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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q) {
      int p = P->val, q = Q->val;
      if(p>q){
         int temp = q;
         q=p;
         p=temp;
      }
      if(p==root->val || q==root->val || (p<root->val && q > root->val))return root;
      if(p<root->val)return lowestCommonAncestor(root->left,P,Q);
      return lowestCommonAncestor(root->right,P,Q);
    }
};
