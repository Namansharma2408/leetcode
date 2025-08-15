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
    pair<int,ListNode*> Size(ListNode* head){
        ListNode* temp = head;
        int size = 1;
        while(temp && temp->next){
            size++;
            temp = temp->next;
        }
        return {size,temp};
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0 ) return head;
        if( head == NULL ) return NULL;
        pair<int,ListNode*> p = Size(head);
        int size = p.first;
        if( size == 1) return head;
        ListNode* last = p.second;
        k %= size;
        if( k == 0 ) return head;
        ListNode* newHead = head;
        int i = size;
        ListNode* newLast = head;
        while( i > k + 1 ){
            newLast = newLast->next;
            i--;
        }
        newHead = newLast->next;
        newLast->next = NULL;
        last->next = head;
        return newHead;
    }
};  
