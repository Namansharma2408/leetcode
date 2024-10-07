class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while( list1 != NULL && list2 != NULL){
            if( list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        
        }
        if( list1 == NULL) temp->next = list2;
        else if( list2 == NULL) temp->next = list1;
        return c->next;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if( n == 0) return NULL;
        if( n == 1) return lists[0];
        while( n > 1){
            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());
            ListNode* c = mergeTwoLists(a,b);
            lists.push_back(c);
            n--;
        }
        return lists[0];
    }
};
