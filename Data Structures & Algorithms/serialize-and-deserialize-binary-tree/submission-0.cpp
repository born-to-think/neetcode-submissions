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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#,";

        stringstream ss;
        ss << root->val << ',';
        ss << serialize(root->left);
        ss << serialize(root->right);
        
        string s = ss.str();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        TreeNode *dummy = new TreeNode();
        stack<pair<TreeNode *,bool>> stk; //{node, bool left? }

        stk.push(  { dummy, true } );
        
        stringstream ss(data);
        string token;
        while(getline(ss, token, ',')){
            auto prev = stk.top();stk.pop();

            TreeNode* curr;
            if(token[0]=='#'){
                curr = nullptr;
            }else{
                int curr_val = stoi(token);
                curr = new TreeNode(curr_val);

                stk.push({curr,false});
                stk.push({curr,true});

            }
            
            TreeNode* prev_node = prev.first;
            bool to_be_insereted_in_left = prev.second;

            to_be_insereted_in_left ? prev_node->left=curr : prev_node->right = curr; 


        }

        return dummy->left;
    }
};
