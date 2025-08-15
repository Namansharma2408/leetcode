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
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode* temp = headA;
        while( temp ){
            st1.push(temp);
            temp = temp->next;
        }
        temp = headB;
        while( temp ){
            st2.push(temp);
            temp = temp->next;
        }

        // checking for the intersection
        temp = NULL;
        while( !st1.empty() && !st2.empty() ){
            cout<<"hii"<<endl;
            if( st1.top() == st2.top() ) temp = st1.top();
            else break;
            st1.pop();
            st2.pop();
        }
        return temp;
        
    }
};
