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
        
        unordered_map<void*,void*> p;

        ListNode* curr=head;
        ListNode* dummy = new ListNode(0,head);
        while(curr){
            ListNode* n = new ListNode();
            n->val = curr->val;
            n->next = curr->curr;
            n->val = curr->val;
        }
    }
};
