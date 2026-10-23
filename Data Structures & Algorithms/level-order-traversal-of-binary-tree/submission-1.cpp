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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root){
            queue<TreeNode *> q;
            q.push(root);

            int n = 1;

            while(n){
                vector<int> v(n);
                int temp_next_n = 0;

                for(int i=0; i<n; i++){
                    TreeNode *curr = q.front(); q.pop();
                    v[i] = curr->val;
                    if(curr->left){
                        q.push(curr->left);
                        temp_next_n++;
                    }
                    if(curr->right){
                        q.push(curr->right);
                        temp_next_n++;
                    }
                }

                ans.push_back(v);
                n = temp_next_n;
            }
        }

        return ans;
    }
};
