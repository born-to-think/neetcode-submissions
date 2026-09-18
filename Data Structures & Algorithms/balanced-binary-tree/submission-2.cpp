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


    int height(TreeNode *parent, bool& flag){

        int hlc;
        hlc = (parent->left == nullptr)? 0 : 1 + height(parent->left, flag);
        int hrc ;
        hrc = (parent->right == nullptr) ? 0 : 1+ height(parent->right, flag);

        if(abs(hlc - hrc) > 1 )flag = false;
        return max(hlc,hrc);

    }
    

    bool isBalanced(TreeNode* root) {
        bool flag = true;
        if(root==nullptr)return flag;
        int h = height(root, flag);

        return flag;

    }
};
