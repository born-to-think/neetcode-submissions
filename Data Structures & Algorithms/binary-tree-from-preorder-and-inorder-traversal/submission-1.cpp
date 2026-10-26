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

    int in_map[6001];
    int pre_idx;
    int in_idx;
    int n;

    TreeNode* buildTree2(vector<int>& preorder,vector<int>& inorder, int stop_val)
    {
        if(pre_idx == n || inorder[in_idx] == stop_val ) {in_idx++;return nullptr;}

        int curr_node_val = preorder[pre_idx];
        TreeNode* root = new TreeNode(curr_node_val);
        pre_idx ++; //this is medatory for next node in series
        

        root->left = buildTree2(preorder, inorder, curr_node_val);

        // our in_idx started from 0
        //at this point, our in_idx will be such that inorder[in_idx] = curr_node_val;
        // in_idx++; //for bypassing the current root and moving on for right subtree now;
        
        
        root->right = buildTree2(preorder, inorder, stop_val);

        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        pre_idx = 0;
        in_idx=0;

        //3001 for tricking the first loop with NO stop value bcz 3001 is out of range in constraints
        return buildTree2(preorder,inorder,3001);

    }
};