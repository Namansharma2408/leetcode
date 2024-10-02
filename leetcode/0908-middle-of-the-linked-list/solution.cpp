class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // int count = 1;
        // ListNode* temp = head;
        // while( temp != NULL){
        //     count++;
        //     temp = temp->next;
        // }
        // count = (count+1)/2 ;
        // temp = head;
        // while(count > 1){
        //     temp = temp->next;
        //     count--;
        // }
        // return temp;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while( fastPtr != NULL && fastPtr->next != NULL) slowPtr = slowPtr->next,fastPtr = fastPtr->next->next;
        return slowPtr;
    }
};
