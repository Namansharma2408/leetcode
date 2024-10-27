
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num = 0;
        ListNode* temp = head;
        while( temp ){
            if( num > k) break;
            num++;
            temp = temp->next;
        }
        if( num < k) return head;

        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n = head;
        int i = 0;
        while(i<k){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
            i++;
        }
        head->next = reverseKGroup(n,k);
        return p;

    }
};
