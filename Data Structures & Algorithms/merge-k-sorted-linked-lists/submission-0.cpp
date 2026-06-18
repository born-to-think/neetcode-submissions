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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int k=0;k<lists.size();k++){
            if(lists[k]) pq.push( {lists[k]->val , k} );
            else pq.push( {1001,k});
        }

        ListNode*dummy = new ListNode();
        ListNode*curr = dummy;
        while(pq.top().first<1001){
            int k = pq.top().second;
            curr->next = lists[k];
            curr=curr->next;
            pq.pop();

            lists[k]=lists[k]->next;
            if(lists[k]){
                pq.push( {lists[k]->val , k} );
            }else{
                pq.push( {1001,k} );
            }
        }

        return dummy->next;

    }
};
