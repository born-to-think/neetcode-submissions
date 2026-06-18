/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*> mp;
        
        Node*curr = head;
        while(curr){
            mp[curr] = new Node(curr->val);
            curr=curr->next;
        }
        
        curr = head;
        Node* dummy = new Node(0);
        Node* dum_curr = dummy;
        
        while(curr){
            dum_curr->next = mp[curr];
            dum_curr = dum_curr->next;
            dum_curr->next = mp[curr->next];
            dum_curr->random = mp[curr->random];
            curr=curr->next; 
        }
        return dummy->next;
    }
};
