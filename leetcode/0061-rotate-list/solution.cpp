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
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || k == 0 || !head->next) return head;
        ListNode* temp = head;
        int size = 1;
        while( temp->next != NULL){
            temp = temp->next;
            size++;
        }
        k = k%size;
        temp->next = head;
        temp = head;
        int i = 1;
        while( i < size-k){
            temp = temp->next;
            i++;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
