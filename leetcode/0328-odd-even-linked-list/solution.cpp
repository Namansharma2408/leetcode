
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* lo = new ListNode(100);
        ListNode* hi = new ListNode(100);
        ListNode* templo = lo;
        ListNode* temphi = hi;
        ListNode* temp = head;
        int n = 1;
        while( temp != NULL){
            if( n%2) templo->next = temp,temp = temp->next,templo = templo->next;
            else temphi->next = temp,temp = temp->next,temphi = temphi->next;
            n++;
        }
        templo->next = hi->next;
        temphi->next = NULL;
        return lo->next;
    }
};
