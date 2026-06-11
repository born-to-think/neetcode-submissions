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
    void reorderList(ListNode* head) {
        int size=0;
        ListNode* slow=head;
        ListNode* fast=head;

        stack<ListNode*> st;
        queue<ListNode*> qu;

        while(slow){
            if(fast && fast->next){
                st.push(slow);
                slow=slow->next;
                fast=fast->next->next;
            }else{
                qu.push(slow);
                slow=slow->next;
            }
            size++;
        }

        ListNode* N=qu.front();qu.pop();
        ListNode* P=N;
        
        N->next=0;
        if(size%2==0){
            P=st.top();st.pop();
            P->next=N;
        }
        while(!st.empty()){
            N=qu.front();qu.pop();
            N->next=P;
            P=st.top();st.pop();
            P->next=N;
        }


    }
};