/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool b  = false;
        while( fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast){
                b = true;
                break;
            }
        }
        if( b == false) return NULL;
        else{
            ListNode* temp = head;
            while( temp != slow){
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }
    }
};
