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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp = head;
        // int size = 0;
        // while( temp != NULL){
        //     temp = temp->next;
        //     size++;
        // }
        // if( n == size){
        //     head = head->next;
        //     return head;
        // }
        // n = size  - n;
        // temp = head;
        // while( n > 1){
        //     temp = temp->next;
        //     n--;
        // }
        // temp->next = temp->next->next;
        // return head;


        ListNode* slow = head;
        ListNode* fast = head;
        int i = 0;
        while( i < n){
            if( fast == NULL) return NULL;
            fast = fast->next;
            i++;
        }
        if( fast == NULL){
            head = head->next;
            return head;
        }
        while( fast->next!= NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};



















