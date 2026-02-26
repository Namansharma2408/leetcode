class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list1;
        ListNode* temp3 = list1;
        ListNode* temp4 = list2;
        ListNode* temp5 = list2;
        for( int i = 1 ; i < a ; i++ ){
            temp1 = temp1->next;
        }
        temp2 = temp1;
        for( int i = a ; i <= b ; i++ ){
            temp2 = temp2->next;
        }
        temp3 = temp2->next;
        while( temp5 && temp5->next ){
            temp5 = temp5->next;
        }
        temp5 = temp5;
        // cout<<temp1->val<<endl<<temp2->val<<endl<<temp3->val<<endl<<temp4->val<<endl<<temp5->val<<endl;
        temp1->next = temp4;
        temp2->next = NULL;
        temp5->next = temp3;
        return list1;
    }
};
