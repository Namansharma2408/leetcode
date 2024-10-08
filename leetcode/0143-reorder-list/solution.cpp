class Solution {
public:
    void reorderList(ListNode* head) {
        if( head->next == NULL || head->next->next == NULL) return;
        ListNode* a= head; 
        ListNode* b= head->next; 
        ListNode* c= NULL; 
        ListNode* d= NULL; 
        ListNode* temp = head;
        while( temp->next->next) temp = temp->next;
        c = temp;
        d = temp->next;
        a->next = d;
        d->next = b;
        c->next = NULL;
        reorderList(b);
    }
};
