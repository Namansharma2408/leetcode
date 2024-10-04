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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( headA == headB ) return headA;
        ListNode* tempa = headA;
        ListNode* tempb = headB;
        int sizea = 0;
        int sizeb = 0;
        while( tempa != NULL){
            sizea++;
            tempa = tempa->next;
        }
        while( tempb != NULL){
            sizeb++;
            tempb = tempb->next;
        }
        tempa = headA,tempb = headB;
        if( sizea > sizeb){
            for( int i = 0 ; i < sizea-sizeb ; i++){
                tempa = tempa->next;
            }
        }
        else if( sizea < sizeb){
            for( int i = 0 ; i < sizeb-sizea ; i++){
                tempb = tempb->next;
            }
        }
        while( tempa != tempb){
            tempa = tempa->next;
            tempb = tempb->next;
        }
        return tempa;
    }
};
