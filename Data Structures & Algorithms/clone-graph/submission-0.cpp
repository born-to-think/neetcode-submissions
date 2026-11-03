/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:


    Node* cloneGraph(Node* node) {
        if(!node)return node;
        queue<Node*> oq;
        unordered_map<Node*, Node*> mp;

        mp[node] = new Node(node->val);
        oq.push(node);

        while(!oq.empty()){
            Node* orgNode = oq.front();oq.pop();
            Node* cpyNode = mp[orgNode];

            cpyNode->neighbors.reserve(orgNode->neighbors.size());
            for(Node* neighbor:orgNode->neighbors){
                if(mp.find(neighbor)==mp.end()){
                    mp[neighbor] = new Node(neighbor->val);
                    oq.push(neighbor);   
                }
                cpyNode->neighbors.push_back(mp[neighbor]);
            } 
        }

        return mp[node];
    }
};
