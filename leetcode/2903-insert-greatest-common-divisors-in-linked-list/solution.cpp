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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while( temp != NULL && temp->next != NULL){
            int num = gcd(temp->val,temp->next->val);
            ListNode* numb = new ListNode(num);
            numb->next = temp->next;
            temp->next = numb;
            temp = temp->next->next;
        }
        return head;
    }
};
