/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* left = dummy;
        ListNode*right = dummy->next;

        while(right){
            int i = 0;
            while(i<k && right){
                i++;
                right = right->next;
            }
            if(i==k){
                

                ListNode* prev = right;
                ListNode*curr = left->next;
                while(curr!=right){
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }
                ListNode* temp = left->next;
                left->next = prev;
                left = temp;
            }
            else break;
        }
        return dummy->next;

    }
};
