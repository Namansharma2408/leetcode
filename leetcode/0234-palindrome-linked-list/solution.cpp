class Solution {
public:
ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n = head;
        while(c){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newHead;
        while(b){
            if( a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};
