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
    int i = -1;
    ListNode* compute(ListNode* curr,  int n){
        if(!curr){
            i=0;
            return 0;
        }
        ListNode* next = compute(curr->next, n);
        if(i==n){
            curr->next=next->next;
        }
        else if (i>=0){
            curr->next = next;
        }
        i++;
        return curr;
        

        

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        return compute(dummy,n)->next;
    }
};
